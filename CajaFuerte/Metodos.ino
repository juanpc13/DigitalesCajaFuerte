boolean RootLogIn() {
  //Verificar el Pin
  keypadControl.resetPin();
  while (!keypadControl.isRootPin()) {
    if (keypadControl.getKey() == 'C') {
      return false;
    }
    keypadControl.keyPadLoop();
    if (millis() % 1000 == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1-Administrador");
      lcd.setCursor(0, 1);
      lcd.print("Pin Principal");
    }
  }
  LDC_OK("1-Administrador");
  //Verificar Huella
  while (fingerController.getFingerprintIDez() != 1) {
    if (keypad.getKey() == 'C') {
      return false;
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1-Administrador");
    lcd.setCursor(0, 1);
    lcd.print("HuellaPrincipal");
    delay(500);
  }
  LDC_OK("1-Administrador");
  //Verificar Tarjeta
  while (rfidContol.getID() != 1) {
    if (keypad.getKey() == 'C') {
      return false;
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1-Administrador");
    lcd.setCursor(0, 1);
    lcd.print("TarjetaPrincipal");
    delay(500);
  }
  if (!rfidContol.isRootCard()) {
    return false;
  }
  LDC_OK("1-Administrador");
  return true;
}

void LDC_OK(String topM) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(topM);
  //lcd.print("1-Administrador");
  lcd.setCursor(0, 1);
  lcd.print("...OK");
  delay(1500);
}

void LDC_CANCEL() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Cancelando");
  lcd.setCursor(0, 1);
  lcd.print("No Admin");
  delay(1500);
}

void RootClean() {
  rfidContol.resetCard();
  keypadControl.resetPin();
  fingerController.resetTemFinger();
}

void RegistrarPersona() {
  //Registrar su Pin
  while (keypad.getKey() != 'C') {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("2-AgregarPersona");
    lcd.setCursor(0, 1);
    lcd.print("Ingrese Huella");
    delay(500);
    break;
  }
}
