#define REDPIN 5
#define GREENPIN 3
#define BLUEPIN 9

String incoming = "";

byte red = 0;
byte blue = 0;
byte green = 0;
 
void setup() {
  Serial.begin(9600);

  Serial.setTimeout(3);
  
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop(){

  if (Serial.available() > 0) {
    String message = Serial.readString();

    Serial.println(message);

    int red_index = -1;
    int green_index = -1;
    int blue_index = -1;

    red_index = message.indexOf("R:");
    green_index = message.indexOf("G:");
    blue_index = message.indexOf("B:");

    //Serial.print(red_index);
    //Serial.print(green_index);
    //Serial.println(blue_index);

    if (red_index != -1) {
      String val = "";
      for (int i = 2; i <= 4; i++) {
        if (isDigit(message[red_index + i])) {
          val = val + message[red_index + i];
        }else{
          break;
        }
      }
      //Serial.println("val:" + val);
      analogWrite(REDPIN, val.toInt());
    }
    if (green_index != -1) {
      String val = "";
      for (int i = 2; i <= 4; i++) {
        if (isDigit(message[green_index + i])) {
          val = val + message[green_index + i];
        }else{
          break;
        }
      }
      //Serial.println("val:" + val);
      analogWrite(GREENPIN, val.toInt());
    }
    if (blue_index != -1) {
      String val = "";
      for (int i = 2; i <= 4; i++) {
        if (isDigit(message[blue_index + i])) {
          val = val + message[blue_index + i];
        }else{
          break;
        }
      }
      //Serial.println("val:" + val);
      analogWrite(BLUEPIN, val.toInt());
    }
  
    //Serial.println("done?");
  }
  
}

