
// Initial display fill
void fill()
{
  lcd.setCursor(0, 0);
  // pac1
  lcd.write(0);
  for (int j = 0; j < 7; j++)
  {
    lcd.print(" ");
    // pill
    lcd.write(2);
  }
  
  lcd.setCursor(0, 1);
  // pill
  lcd.write(2);
  
  for (int j = 0; j < 7; j++)
  {
    lcd.print(" ");
    // pill
    lcd.write(2);
  }
}

// character animation
void anim()
{
  lcd.setCursor(px, py);
  lcd.print(" ");
  lcd.setCursor(x, y);
  //pac2
  lcd.write(1);
  delay(del);
  lcd.setCursor(x, y);
  //pac1
  lcd.write(0);
  delay(del);
  px = x;
  py = y;
}
