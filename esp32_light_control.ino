// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "Galaxy S9+18a5";
const char* password = "organiza";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";
String output33State = "off";
String output32State = "off";
String output14State = "off";
String output12State = "off";
String output13State = "off";

// Assign output variables to GPIO pins
const int output26 = 26;
const int output27 = 27;
const int output33 = 33;
const int output32 = 32;
const int output14 = 14;
const int output12 = 12;
const int output13 = 13;
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

// Define Authentication
const char* base64Encoding = "m";


void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  pinMode(output33, OUTPUT);
  pinMode(output32, OUTPUT);
  pinMode(output14, OUTPUT);
  pinMode(output12, OUTPUT);
  pinMode(output13, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);
  digitalWrite(output33, LOW);
  digitalWrite(output32, LOW);
  digitalWrite(output14, LOW);
  digitalWrite(output12, LOW);
  digitalWrite(output13, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // check base64 encode for authentication
            // Finding the right credentials
            if (header.indexOf(base64Encoding) >= 0)
            {

              // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
              // and a content-type so the client knows what's coming, then a blank line:
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println("Connection: close");
              client.println();
              // turns the GPIOs on and off
              if (header.indexOf("GET /26/on") >= 0) {
                Serial.println("GPIO 26 on");
                output26State = "on";
                digitalWrite(output26, HIGH);
              } else if (header.indexOf("GET /26/off") >= 0) {
                Serial.println("GPIO 26 off");
                output26State = "off";
                digitalWrite(output26, LOW);
              } else if (header.indexOf("GET /27/on") >= 0) {
                Serial.println("GPIO 27 on");
                output27State = "on";
                digitalWrite(output27, HIGH);
              } else if (header.indexOf("GET /27/off") >= 0) {
                Serial.println("GPIO 27 off");
                output27State = "off";
                digitalWrite(output27, LOW);
              } if (header.indexOf("GET /33/on") >= 0) {
                Serial.println("GPIO 33 on");
                output33State = "on";
                digitalWrite(output33, HIGH);
              } else if (header.indexOf("GET /33/off") >= 0) {
                Serial.println("GPIO 33 off");
                output33State = "off";
                digitalWrite(output33, LOW);
              } if (header.indexOf("GET /32/on") >= 0) {
                Serial.println("GPIO 32 on");
                output32State = "on";
                digitalWrite(output32, HIGH);
              } else if (header.indexOf("GET /32/off") >= 0) {
                Serial.println("GPIO 32 off");
                output32State = "off";
                digitalWrite(output32, LOW);
              } if (header.indexOf("GET /14/on") >= 0) {
                Serial.println("GPIO 14 on");
                output14State = "on";
                digitalWrite(output14, HIGH);
              } else if (header.indexOf("GET /14/off") >= 0) {
                Serial.println("GPIO 14 off");
                output14State = "off";
                digitalWrite(output14, LOW);
              } if (header.indexOf("GET /12/on") >= 0) {
                Serial.println("GPIO 12 on");
                output12State = "on";
                digitalWrite(output12, HIGH);
              } else if (header.indexOf("GET /12/off") >= 0) {
                Serial.println("GPIO 12 off");
                output12State = "off";
                digitalWrite(output12, LOW);
              } if (header.indexOf("GET /13/on") >= 0) {
                Serial.println("GPIO 13 on");
                output13State = "on";
                digitalWrite(output13, HIGH);
              } else if (header.indexOf("GET /13/off") >= 0) {
                Serial.println("GPIO 13 off");
                output13State = "off";
                digitalWrite(output13, LOW);
              }

              // Display the HTML web page
              client.println("<!DOCTYPE html><html>");
              client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
              client.println("<link rel=\"icon\" href=\"data:,\">");
              // CSS to style the on/off buttons
              // Feel free to change the background-color and font-size attributes to fit your preferences
              client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
              client.println(".button { background-color: #98fb98; border:none; color: black; padding: 10px 40px;border-radius: 25px; outline : 2px solid black; width: 300px");
              client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
              client.println(".button2 {background-color: red;}</style></head>");

              // Web Page Heading
              client.println("<body><h1>SMART HOME</h1>");

              // Display current state, and ON/OFF buttons for GPIO 26
              client.println("<p>downstairs lights - State " + output26State + "</p>");
              // If the output26State is off, it displays the ON button
              if (output26State == "off") {
                client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
              }

              // Display current state, and ON/OFF buttons for GPIO 27
              client.println("<p>downstairs room 1 - State " + output27State + "</p>");
              // If the output27State is off, it displays the ON button
              if (output27State == "off") {
                client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
              }
              client.println("</body></html>");

              // Display upstairs
              client.println("<p>downstairs room 2 - State " + output33State + "</p>");
              // If the output26State is off, it displays the ON button
              if (output33State == "off") {
                client.println("<p><a href=\"/33/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/33/off\"><button class=\"button button2\">OFF</button></a></p>");
              }

              // Display current state, and ON/OFF buttons for GPIO 27
              client.println("<p>upstairs light - State " + output32State + "</p>");
              // If the output27State is off, it displays the ON button
              if (output32State == "off") {
                client.println("<p><a href=\"/32/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/32/off\"><button class=\"button button2\">OFF</button></a></p>");
              }

              // Display current state, and ON/OFF buttons for upstairs rooms
              client.println("<p>upstairs room 1 - State " + output14State + "</p>");
              // If the output27State is off, it displays the ON button
              if (output14State == "off") {
                client.println("<p><a href=\"/14/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/14/off\"><button class=\"button button2\">OFF</button></a></p>");
              }

              client.println("<p>upstairs room 2 - State " + output12State + "</p>");
              // If the output27State is off, it displays the ON button
              if (output12State == "off") {
                client.println("<p><a href=\"/12/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/12/off\"><button class=\"button button2\">OFF</button></a></p>");
              }

              client.println("<p>upstairs room 3 - State " + output13State + "</p>");
              // If the output27State is off, it displays the ON button
              if (output13State == "off") {
                client.println("<p><a href=\"/13/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/13/off\"><button class=\"button button2\">OFF</button></a></p>");
              }
              client.println("</body></html>");

              // The HTTP response ends with another blank line
              client.println();
              // Break out of the while loop
              break;
            }
            else {
              client.println("HTTP/1.1 401 Unauthorized");
              client.println("WWW-Authenticate: Basic realm=\"Secure\"");
              client.println("Content-Type: text/html");
              client.println();
              client.println("<html>Authentication failed</html>");
              pinMode(18, OUTPUT);
              digitalWrite(18, HIGH);

            }
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
