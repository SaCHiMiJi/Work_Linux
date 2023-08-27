const int SER = 8;
// Serial output to shift register
const int LATCH = 9;
// Shift register latch pin
const int CLK = 10;
// Shift register clock pin
void setup()
{
    // Set pins as outputs
    pinMode(SER, OUTPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLK, OUTPUT);
    digitalWrite(LATCH, LOW);
    // Latch low
    shiftOut(SER, CLK, MSBFIRST, B10101010);
    // Shift most sig. bit first
    digitalWrite(LATCH, HIGH);
    // Latch high -show pattern
void loop()
{
    // Do nothing
}