#include "WiFi.h"
#include <SPIFFS.h>
#include <WebServer.h>

//webserver
WebServer server(80);

void createWebServer()
{
  server.on("/", []() {
    String html_content = "";
    html_content += "<!DOCTYPE html>\n";
    html_content += "<html lang=\"en\">\n";
    html_content += "<head>\n";
    html_content += "    <meta charset=\"UTF-8\">\n";
    html_content += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    html_content += "    <title>ESP32 Web Server</title>\n";
    html_content += "    <style>\n";
    html_content += "        body {\n";
    html_content += "            font-family: Arial, sans-serif;\n";
    html_content += "            text-align: center;\n";
    html_content += "            background-color: #f4f4f4;\n";
    html_content += "            padding: 20px;\n";
    html_content += "        }\n";
    html_content += "        .container {\n";
    html_content += "            max-width: 400px;\n";
    html_content += "            margin: 0 auto;\n";
    html_content += "            background: white;\n";
    html_content += "            padding: 20px;\n";
    html_content += "            border-radius: 10px;\n";
    html_content += "            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);\n";
    html_content += "        }\n";
    html_content += "        h1 {\n";
    html_content += "            color: #333;\n";
    html_content += "        }\n";
    html_content += "        .creator {\n";
    html_content += "            font-size: 18px;\n";
    html_content += "            margin: 20px 0;\n";
    html_content += "        }\n";
    html_content += "        .explain {\n";
    html_content += "            font-size: 18px;\n";
    html_content += "            margin: 20px 0;\n";
    html_content += "        }\n";
    html_content += "    </style>\n";
    html_content += "</head>\n";
    html_content += "<body>\n";
    html_content += "    <div class=\"container\">\n";
    html_content += "        <h1>ESP32 Web Server</h1>\n";
    html_content += "        <p class=\"creator\">Creator: <span>Skillstorm</span></p>\n";
    html_content += "        <p class=\"explain\">Explain: <span>Now, You can add a button to control LED on ESP32</span></p>\n";
    html_content += "    </div>\n";
    html_content += "\n";
    html_content += "</body>\n";
    html_content += "</html>\n";

    server.send(200, "text/html", html_content);
  });
}

void Websetup()
{
  server.begin();
  createWebServer();
}

void Webloop()
{
  server.handleClient();
}
