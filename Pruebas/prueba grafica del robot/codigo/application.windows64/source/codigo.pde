import processing.serial.*;
import g4p_controls.*;
PImage img;
boolean      printSerial = false;
final String serialConfigFile = "serialconfig.txt";
// UI controls.
GPanel    configPanel;
GDropList serialList;
GLabel    serialLabel;
GCheckbox printSerialCheckbox;
float valorpasado;
Serial myPort; 
String valor;     
void setup() {
  size(300, 300);
   frameRate(30);

  int selectedPort = 0;
  String[] availablePorts = Serial.list();
  if (availablePorts == null) {
    println("ERROR: No serial ports available!");
    exit();
  }
  String[] serialConfig = loadStrings(serialConfigFile);
  if (serialConfig != null && serialConfig.length > 0) {
    String savedPort = serialConfig[0];
    // Check if saved port is in available ports.
    for (int i = 0; i < availablePorts.length; ++i) {
      if (availablePorts[i].equals(savedPort)) {
        selectedPort = i;
      } 
    }
  }
  // Build serial config UI.
  configPanel = new GPanel(this, 10, 10, width-20, 90, "Configuration (click to hide/show)");
  serialLabel = new GLabel(this,  0, 20, 80, 25, "Serial port:");
  configPanel.addControl(serialLabel);
  serialList = new GDropList(this, 90, 20, 200, 200, 6);
  serialList.setItems(availablePorts, selectedPort);
  configPanel.addControl(serialList);
    String portName = Serial.list()[selectedPort];
  myPort = new Serial(this, portName, 115200);

}


void draw() {
  imageMode(CENTER);
  img = loadImage("robot.png");
  if (myPort.available()>0) { 
    valor = myPort.readString();  
    translate(width/2, height/2);
    String[] list = split(valor, " ");
    float rad = radians(float(list[0]));

    if (rad == rad) {    

      rotate(rad);
      background(255); 
      image(img, 0, 0);
      resetMatrix();
    }
  }
}
void setSerialPort(String portName) {
  // Close the port if it's currently open.
  if (myPort != null) {
    myPort.stop();
  }
  try {
    // Open port.
    myPort = new Serial(this, portName, 115200);
    myPort.bufferUntil('\n');
    // Persist port in configuration.
    saveStrings(serialConfigFile, new String[] { portName });
  }
  catch (RuntimeException ex) {
    // Swallow error if port can't be opened, keep port closed.
    myPort = null; 
  }
}

// UI event handlers

void handlePanelEvents(GPanel panel, GEvent event) {
  // Panel events, do nothing.
}

void handleDropListEvents(GDropList list, GEvent event) { 
  // Drop list events, check if new serial port is selected.
  if (list == serialList) {
    setSerialPort(serialList.getSelectedText()); 
  }
}

void handleToggleControlEvents(GToggleControl checkbox, GEvent event) { 
  // Checkbox toggle events, check if print events is toggled.
  if (checkbox == printSerialCheckbox) {
    printSerial = printSerialCheckbox.isSelected(); 
  }
}
