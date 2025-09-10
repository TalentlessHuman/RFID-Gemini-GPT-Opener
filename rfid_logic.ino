#include <SPI.h>
#include <MFRC522.h>

// - PIN Configuration -
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

// STEP 1: Change this to true if you want to get UIDs, then false for normal use
bool GET_UID_MODE = false;

// STEP 2: Replace these UIDs with your card/tag UIDs
String portfolioCardUid = "9B 14 97 04";  // <-- Replace with your portfolio card UID
String geminiTokenUid   = "A6 31 7E 05";  // <-- Replace with your Gemini token UID

// Delay to prevent multiple triggers from one scan
long readDelay = 1000;
long lastReadTime = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial connection
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("Verifying MFRC522 connection...");
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println();

  if (GET_UID_MODE) {
    Serial.println("UID SCANNER MODE: Scan a tag to read UID...");
  } else {
    Serial.println("Arduino is ready. Run the Python script on your laptop.");
  }
}

void loop() {
  // Prevent multiple reads within delay
  if (millis() - lastReadTime < readDelay) return;

  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) return;

  // Build UID string
  String currentUid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    currentUid += (mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    currentUid += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) currentUid += " ";
  }
  currentUid.toUpperCase();
  currentUid.trim();

  // - Main Logic -
  if (GET_UID_MODE) {
    Serial.print("Tag UID found: ");
    Serial.println(currentUid);
  } else {
    if (currentUid.equals(portfolioCardUid)) {
      Serial.println("OPEN_PORTFOLIO");
    } else if (currentUid.equals(geminiTokenUid)) {
      Serial.println("OPEN_GEMINI");
    } else {
      Serial.print("Unrecognized tag: ");
      Serial.println(currentUid);
    }
  }

  // Halt card and update timer
  mfrc522.PICC_HaltA();
  lastReadTime = millis();
}
