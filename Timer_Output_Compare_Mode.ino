void setup()
{
  //Enable the Global Interrupt Enable Bit
  SREG |= (1<<7);

  //Enable the Required Timer Interrupt
  TIMSK1 |= (1<<OCIE1A);

  //Set Mode of the  Timer
  TCCR1A &= (~(1<<WGM10)) & (~(WGM11));
  TCCR1B &= (~(1<<WGM12)) & (~(WGM13)); // Normal Mode

  //Set the Compare Output Mode
  TCCR1A |= (1<<COM1A0);
  TCCR1A &= (~(1<<COM1A1)); // Toggle

  //Set the Prescaler for the Timer
  TCCR1B |=  (1<<CS12) | (1<<CS10);
  TCCR1B &=  (~(1<<CS11)); // Prescaler = 1024

  //Start the Period for the Timer
  TCNT1 = 0;

  //Load the period for the Timer
  OCR1A = 15625;

  //Configure the Output Compare Pin as Output
  DDRB |= (1<<DDB1);
}

void loop()
{

}

//Implement the ISR Function
ISR(TIMER1_COMPA_vect)
{
  TCNT1 = 0;
  OCR1A = 15625;
}