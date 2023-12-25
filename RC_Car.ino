#define light_FR  14    //LED Front Right
#define light_FL  15    //LED Front Left
#define light_BR  16    //LED Back Right
#define light_BL  17    //LED Back Left
#define horn_Buzz 18    //Horn Buzzer   

int command;

bool moveForward = false;
bool moveBackward = false;
bool turnLeft = false;
bool turnRight = false;
bool lightFront = false;
bool lightBack = false;
bool horn = false;

void setup() {
  pinMode(light_FR, OUTPUT);
  pinMode(light_FL, OUTPUT);
  pinMode(light_BR, OUTPUT);
  pinMode(light_BL, OUTPUT);
  pinMode(horn_Buzz, OUTPUT);

  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

/*

  Just write forward(), back(), left(), right() and stop() function and you are good to go.

*/


void forward() {

}

void back() {

}

void left() {

}

void right() {

}

void Stop() {

}

void loop()
{
  if (moveForward)
  {
    forward();
  }
  else
  {
    Stop();
  }

  if (moveBackward)
  {
    back();
  }
  else
  {
    Stop();
  }

  if (turnLeft)
  {
    left();
  }
  else
  {
    Stop();
  }

  if (turnRight)
  {
    right();
  }
  else
  {
    Stop();
  }

  if (lightFront)
  {
    digitalWrite(light_FR, HIGH);
    digitalWrite(light_FL, HIGH);
  }
  else
  {
    digitalWrite(light_FR, LOW);
    digitalWrite(light_FL, LOW);
  }

  if (lightBack)
  {
    digitalWrite(light_BR, HIGH);
    digitalWrite(light_BL, HIGH);
  }
  else
  {
    digitalWrite(light_BR, LOW);
    digitalWrite(light_BL, LOW);
  }

  if (horn)
  {
    digitalWrite(horn_Buzz, HIGH);
  }
  else
  {
    digitalWrite(horn_Buzz, LOW);
  }

  if (Serial.available() > 0) {

    command = (char)Serial.read();
    Serial.println(command);

    switch (command) {
      case 'F':
        moveForward = true;
        break;
      case 'f':
        moveForward = false;
        break;
      case 'B':
        moveBackward = true;
        break;
      case 'b':
        moveBackward = false;
        break;
      case 'L':
        turnLeft = true;
        break;
      case 'l':
        turnLeft = false;
        break;
      case 'R':
        turnRight = true;
        break;
      case 'r':
        turnRight = false;
        break;
      case 'U':
        lightFront = true;
        break;
      case 'u':
        lightFront = false;
        break;
      case 'V':
        lightBack = true;
        break;
      case 'v':
        lightBack = false;
        break;
      case 'W':
        horn = true;
        break;
      case 'w':
        horn = false;
        break;

      default: Stop();
    }
  }
}
