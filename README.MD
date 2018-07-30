# Arduino Robotic Arm Controller

Arduino program to control the servo motors on our robotic arm.

## Getting Started

Easy peasy code

### Prerequisites

Software needed:

```
Arduino IDE (Or any other arduino compiler)
```

### Installing

Clone the project and flash the servo.ino file.


## Usage

Orders are passed to the serial as a JSON with 3 variables

```
{"servo":1,"direction":"P","angle":50}
```

### servo

1-5 integer used to select the motor to move



### direction

1/0 integer to specify the direction
1 = forward
0 = backwards

### angle

1-180 integer to define how much will the servo move


## Built With

* [ArduinoJson](https://arduinojson.org/) - Arduino library used to parse the JSON orders.

## Authors

* **Alberto Zugazagoitia** - *JSON parsing and code debugging* - [zugazagoitia](https://github.com/zugazagoitia)
* **André Lorenzo Torres** - *JSON parsing and code debugging* - [andrelorenzo](https://github.com/andrelorenzo)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the GNU License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* @cadiducho for the help with the library errors (ty really)

