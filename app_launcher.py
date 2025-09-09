import serial
import serial.tools.list_ports
import webbrowser
import time

# --- URLS TO OPEN ---
PORTFOLIO_URL = "https://bikramsoren.vercel.app"
GEMINI_URL = "https://gemini.google.com/"
BAUD_RATE = 9600

def find_arduino_port():
    """Scans available COM ports and returns the one with an Arduino."""
    ports = serial.tools.list_ports.comports()
    for port in ports:
        # Common Arduino identifiers in port descriptions
        if "Arduino" in port.description or "CH340" in port.description:
            return port.device
    return None

def main():
    """Main function to run the application launcher."""
    arduino_port = find_arduino_port()

    if not arduino_port:
        print("❌ Error: Could not find an Arduino. Please check the connection.")
        input("Press Enter to exit.")
        return

    try:
        arduino = serial.Serial(arduino_port, BAUD_RATE, timeout=1)
        print(f"✅ Connection successful! Listening on {arduino_port}...")
        print("Scan your RFID card or token to open a link.")

        while True:
            command = arduino.readline().decode('utf-8').strip()

            if command == "OPEN_PORTFOLIO":
                print("🚀 Admin card scanned. Opening your portfolio...")
                webbrowser.open(PORTFOLIO_URL)
            
            elif command == "OPEN_GEMINI":
                print("🚀 Token scanned. Opening Gemini...")
                webbrowser.open(GEMINI_URL)

    except serial.SerialException:
        print(f"❌ Error: Could not open port {arduino_port}.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()