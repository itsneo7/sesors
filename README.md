## 1. Repository objectives

The purpose of this repository is to build a practical, reusable
collection of sensor experiments that helps answer:

-   How does a sensor work?
-   What physical quantity does it measure?
-   What are its electrical and communication requirements?
-   How can it be connected to a microcontroller or computer?
-   How can raw data be acquired and interpreted?
-   How accurate, repeatable, and stable are its measurements?
-   What calibration or filtering is required?
-   What are its limitations and common failure modes?
-   How can the sensor be integrated into a larger embedded or software
    project?

Every experiment should contain enough information for another person to
reproduce the setup and verify the results.

## 2. Repository structure

A suggested structure is:

``` text
sensor-experimentation/
│
├── README.md
├── CONTRIBUTING.md
├── LICENSE
│
├── distance_sensors/
│   ├── tf_lidar/
│   │   ├── README.md
│   │   ├── wiring/
│   │   ├── code/
│   │   ├── data/
│   │   └── results/
│   ├── vl53_tof/
│   ├── ultrasonic/
│   └── ir_proximity/
│
├── motion_and_position/
│   ├── incremental_encoder/
│   ├── magnetic_encoder/
│   ├── hall_effect_sensor/
│   └── potentiometer/
│
├── inertial_sensors/
│   ├── mpu6050/
│   ├── mpu9250/
│   ├── bno085/
│   └── other_imus/
│
├── environmental_sensors/
│   ├── temperature/
│   ├── humidity/
│   ├── pressure/
│   ├── gas_and_air_quality/
│   └── light_intensity/
│
├── force_and_electrical_sensors/
│   ├── load_cell/
│   ├── current_sensor/
│   ├── voltage_sensor/
│   └── strain_gauge/
│
├── positioning_sensors/
│   ├── gps_gnss/
│   ├── compass_magnetometer/
│   └── optical_flow/
│
├── vision_and_scanning/
│   ├── camera/
│   ├── depth_camera/
│   └── 2d_lidar/
│
├── communication_interfaces/
│   ├── uart/
│   ├── i2c/
│   ├── spi/
│   ├── pwm/
│   └── analog_adc/
│
└── common_resources/
    ├── datasheets/
    ├── reference_circuits/
    ├── calibration_tools/
    └── data_analysis/
```

Folders can be added as new sensors are acquired. A folder should only
be treated as an implemented experiment once its hardware, code, and
results have actually been tested.

## 3. Sensor catalogue

The following catalogue defines the intended scope of the repository.
Exact models and board revisions should be recorded in the individual
experiment documentation.

### 3.1 Distance and ranging sensors

  -----------------------------------------------------------------------
  Sensor / family   Measurement       Typical interface Experiments
                    principle                           
  ----------------- ----------------- ----------------- -----------------
  TF-Luna / TFmini  Optical           UART / I2C, model Distance
                    time-of-flight    dependent         accuracy, range,
                    ranging                             update rate,
                                                        surface response

  VL53L0X           Optical           I2C               Short-range
                    time-of-flight                      accuracy, timing,
                                                        repeatability

  VL53L1X           Optical           I2C               Range modes,
                    time-of-flight                      timing budget,
                                                        field of view

  Ultrasonic        Ultrasonic pulse  Trigger / Echo    Distance, blind
  HC-SR04           travel time       GPIO              zone,
                                                        target-angle
                                                        effects

  IR proximity      Infrared          Analog / digital  Detection
                    reflection                          threshold,
                                                        ambient-light
                                                        sensitivity

  2D LiDAR          Laser scanning    USB / UART /      Scan quality,
                                      Ethernet, model   range, angular
                                      dependent         resolution
  -----------------------------------------------------------------------

### 3.2 Motion, rotation and position sensors

  -----------------------------------------------------------------------
  Sensor / family   Measurement       Typical interface Experiments
                    principle                           
  ----------------- ----------------- ----------------- -----------------
  Incremental       Optical or        Quadrature A/B,   CPR, direction,
  encoder           magnetic pulse    GPIO, timer       RPM, missed
                    counting                            counts

  Magnetic encoder  Magnetic absolute I2C / PWM /       Angle, zero
  AS5600            angle             analog, board     offset, magnet
                                      dependent         alignment

  Magnetic encoder  Magnetic angular  SPI / I2C, model  Resolution,
  AS5048            measurement       dependent         accuracy, angle
                                                        response

  Hall-effect       Magnetic field    Digital / analog  Switching
  sensor            detection                           threshold, speed
                                                        measurement

  Potentiometer     Variable          Analog ADC        Voltage-angle
                    resistance                          relationship,
                                                        linearity

  Optical flow      Image-based       SPI / I2C, model  Motion
  sensor            surface motion    dependent         estimation,
                                                        surface
                                                        dependence
  -----------------------------------------------------------------------

### 3.3 Inertial and orientation sensors

  -----------------------------------------------------------------------
  Sensor / family   Measurement       Typical interface Experiments
  ----------------- ----------------- ----------------- -----------------
  MPU6050           3-axis            I2C               Bias, noise, axis
                    accelerometer +                     orientation,
                    3-axis gyroscope                    filtering

  MPU9250           Accelerometer +   I2C / SPI         Calibration,
                    gyroscope +                         heading, sensor
                    magnetometer                        fusion

  BNO085            Inertial sensing  I2C / SPI / UART, Orientation,
                    with onboard      board dependent   calibration,
                    fusion features                     drift, report
                                                        rates

  Magnetometer      Magnetic field /  I2C / SPI         Hard-iron and
                    heading reference                   soft-iron
                                                        effects, heading
  -----------------------------------------------------------------------

### 3.4 Environmental sensors

  -----------------------------------------------------------------------
  Sensor / family   Measurement       Typical interface Experiments
  ----------------- ----------------- ----------------- -----------------
  DHT11 / DHT22     Temperature and   Digital           Accuracy,
                    humidity          single-wire       response time
                                      protocol          

  BME280            Temperature,      I2C / SPI         Pressure and
                    humidity,                           environmental
                    pressure                            measurements

  BMP280            Temperature and   I2C / SPI         Pressure
                    pressure                            calibration,
                                                        altitude estimate

  DS18B20           Temperature       1-Wire            Accuracy,
                                                        resolution,
                                                        response time

  MQ-series         Gas-sensitive     Analog / digital  Warm-up,
                    resistance        module output     sensitivity,
                                                        calibration
                                                        limitations

  LDR / photodiode  Light intensity   Analog            Response curve,
                                                        ambient-light
                                                        effects
  -----------------------------------------------------------------------

### 3.5 Force and electrical measurement sensors

  -----------------------------------------------------------------------
  Sensor / family   Measurement       Typical interface Experiments
  ----------------- ----------------- ----------------- -----------------
  Load cell + HX711 Force / weight    Two-wire          Zero offset,
                    through strain    clock/data        calibration,
                    gauge             interface         repeatability

  ACS712            Current           Analog            Offset,
                                                        sensitivity,
                                                        current
                                                        comparison

  INA219 / INA226   Bus voltage and   I2C               Voltage/current
                    current                             accuracy, power
                                                        calculation

  Voltage divider   Voltage           Analog ADC        Scaling, ADC
  module                                                calibration

  Strain gauge      Mechanical strain Wheatstone bridge Bridge output,
                                      / amplifier       loading response
  -----------------------------------------------------------------------

### 3.6 Vision and depth sensors

  -----------------------------------------------------------------------
  Sensor / family   Measurement       Typical interface Experiments
  ----------------- ----------------- ----------------- -----------------
  RGB camera        Colour image      USB / CSI / other Resolution,
                                                        exposure, frame
                                                        rate

  Depth camera      Per-pixel depth   USB / other       Depth accuracy,
                                                        alignment,
                                                        invalid pixels

  Stereo camera     Depth from stereo USB / CSI / other Calibration,
                    disparity                           disparity, depth
                                                        error
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## 4. Standard documentation for every sensor

Each sensor folder should contain a `README.md` with the following
sections. Not every section applies to every sensor; mark irrelevant
sections as not applicable rather than inventing information.

### 4.1 Sensor overview

Document:

-   Full sensor name and exact model.
-   Manufacturer and product link.
-   Sensor IC and breakout-board revision, if known.
-   What physical quantity it measures.
-   Measurement principle.
-   Typical applications.
-   Important limitations.

### 4.2 Technical specifications

Record specifications from the datasheet and clearly distinguish them
from measured results.

  Parameter                Value
  ------------------------ ---------------------------------------
  Supply voltage           To be verified from datasheet
  Logic voltage            To be verified from datasheet
  Measurement range        Datasheet value
  Resolution               Datasheet value
  Accuracy                 Datasheet value and conditions
  Update / sampling rate   Datasheet value
  Interface                UART / I2C / SPI / GPIO / ADC / other
  Operating temperature    Datasheet value
  Datasheet link           Add official document

### 4.3 Pinout and wiring

Include:

-   A pinout image or diagram.
-   A pin-to-pin wiring table.
-   Supply and ground connections.
-   Signal voltage levels.
-   Pull-up or level-shifting requirements.
-   Controller board used for the experiment.

Example format:

  -----------------------------------------------------------------------
  Sensor pin        Controller pin    Purpose           Notes
  ----------------- ----------------- ----------------- -----------------
  VCC               To be specified   Power             Confirm permitted
                                                        voltage

  GND               GND               Ground            Common ground
                                                        where required

  SDA / TX / OUT    To be specified   Data              Depends on
                                                        interface

  SCL / RX / CLK    To be specified   Clock / data      Depends on
                                                        interface
  -----------------------------------------------------------------------

**Electrical safety:** Never assume that a module is 5 V tolerant. Check
the exact breakout-board documentation and the controller's input limits
before connecting signals.

### 4.4 Communication and data acquisition

Explain:

-   Communication protocol.
-   Device address, baud rate, clock rate, or signal format where
    applicable.
-   Required initialisation sequence.
-   Data register or packet format.
-   Raw data type and units.
-   Error/status indicators.
-   How to detect communication failure.

### 4.5 Experimental setup

Describe the equipment and physical arrangement:

-   Sensor and controller.
-   Power supply.
-   Reference instrument, if used.
-   Test target or controlled physical input.
-   Wiring and mounting.
-   Environmental conditions.
-   Software and library versions.

### 4.6 Experimental procedure

Write numbered steps so that the experiment can be repeated by another
person.

### 4.7 Data collection and analysis

Save raw measurements before filtering or calibration. Include units,
timestamps, sample counts, and test conditions.

### 4.8 Results and conclusion

Document measured performance, limitations, unexpected behaviour, and
whether the experiment passed its stated objective.

### 4.9 Troubleshooting

Record symptoms, possible causes, diagnostic steps, and the verified
fix.

------------------------------------------------------------------------

# 5. Experiment guide by sensor category

The following experiments provide a baseline. Adapt the test distances,
speeds, angles, sample counts, and reference equipment to the sensor's
datasheet and intended operating range.

## 5.1 TF LiDAR --- TF-Luna / TFmini family

**Objective:** Understand single-point optical distance measurement and
evaluate the sensor's behaviour under different test conditions.

Experiments:

1.  **Communication test:** Establish UART or I2C communication
    according to the exact model's manual. Verify that packets/register
    readings are valid.
2.  **Basic distance test:** Place a flat target in front of the sensor
    and verify that the reported distance changes as expected.
3.  **Accuracy test:** Compare measurements with a tape measure or
    suitable reference at multiple distances.
4.  **Repeatability test:** Capture repeated samples without moving the
    target. Calculate mean and standard deviation.
5.  **Surface test:** Compare matte, glossy, dark, light, and angled
    targets.
6.  **Ambient-light test:** Compare measurements under different
    lighting conditions supported by the device.
7.  **Update-rate test:** Measure actual readings per second and
    identify dropped or repeated samples.
8.  **Filtering test:** Compare raw data with median and moving-average
    filters.
9.  **Latency test:** Move a target and measure the delay before the
    output reflects the change.

Record the exact TF model. Different TF-Luna and TFmini variants do not
necessarily share the same range, protocol, baud rate, or electrical
characteristics.

## 5.2 VL53 ToF --- VL53L0X / VL53L1X family

**Objective:** Characterise short-range optical time-of-flight
measurements.

Experiments:

1.  Detect and initialise the sensor over I2C.
2.  Record the detected address and any available identification/status
    information.
3.  Measure a fixed target repeatedly.
4.  Compare readings with reference distances.
5.  Test different target surfaces and angles.
6.  Evaluate supported timing-budget and measurement-period settings.
7.  Test the effective field of view by moving a target laterally.
8.  Test multiple modules, if applicable, using the documented
    address-management procedure.
9.  Measure response delay when a target moves.

Do not copy settings from one VL53 variant to another without checking
its datasheet and driver documentation.

## 5.3 Ultrasonic sensor --- HC-SR04 and similar

**Objective:** Understand distance measurement using ultrasonic pulse
travel time.

Experiments:

1.  Verify trigger and echo signal behaviour.
2.  Measure a flat target at several known distances.
3.  Identify the minimum reliable distance and maximum practical range
    in the test setup.
4.  Compare readings from soft, hard, narrow, and angled targets.
5.  Test the effect of nearby surfaces and multiple reflective objects.
6.  Measure update rate and timeout behaviour.
7.  Compare raw readings with median filtering.

The Echo signal on common HC-SR04 modules may be 5 V. Verify controller
input tolerance and use suitable level shifting where required.

## 5.4 Incremental rotary encoder

**Objective:** Understand pulse counting, direction detection, angular
displacement, and rotational speed.

Experiments:

1.  Inspect A and B output signals with an oscilloscope or logic
    analyser.
2.  Rotate the shaft by hand and verify quadrature phase and direction.
3.  Count pulses over one full revolution.
4.  Repeat in both directions and over multiple revolutions.
5.  Compare the measured counts with the manufacturer's PPR/CPR
    definition.
6.  Measure RPM at multiple speeds.
7.  Test low-speed resolution and high-speed missed-count behaviour.
8.  Test counter overflow and timing behaviour.
9.  Compare measured rotation with a reference mark or tachometer.

For a measured count change (`\Delta `{=tex}C), effective counts per
revolution (C\_{`\text{rev}`{=tex}}), and elapsed time
(`\Delta `{=tex}t):

\[ RPM =
`\frac{\Delta C}{C_{\text{rev}}}`{=tex}`\times`{=tex}`\frac{60}{\Delta t}`{=tex}
\]

Clearly document whether the count convention is x1, x2, or x4 decoding.

## 5.5 Magnetic rotary encoder --- AS5600 / AS5048 family

**Objective:** Measure absolute angular position and understand magnetic
alignment requirements.

Experiments:

1.  Establish communication using the exact model's supported interface.
2.  Read raw angle and status information.
3.  Rotate the shaft through a complete revolution and observe angle
    progression and wraparound.
4.  Mark a mechanical reference position and establish a zero offset.
5.  Compare readings at known angles using a suitable reference fixture.
6.  Test repeatability in clockwise and anticlockwise directions.
7.  Investigate the effect of magnet centring, air gap, and tilt within
    manufacturer limits.
8.  Measure update rate and dynamic response.
9.  If used for a limited-travel joint, test the required operating
    range and mechanical limits.

Record the magnet type and mounting geometry. Do not assume AS5600,
AS5048A, and other magnetic encoders use the same interface or register
format.

## 5.6 MPU6050 / MPU-series IMU

**Objective:** Understand accelerometer and gyroscope measurements,
sensor bias, noise, and orientation estimation.

Experiments:

1.  Establish I2C or SPI communication as supported by the exact model.
2.  Read device identity/status information.
3.  Place the sensor in six known orientations and verify axis signs.
4.  Record stationary accelerometer readings.
5.  Estimate accelerometer offset and scale error using known
    orientations.
6.  Keep the sensor still and estimate gyroscope bias.
7.  Rotate around each axis and inspect angular velocity.
8.  Record noise and drift over time.
9.  Compare raw signals with a complementary filter or another
    documented fusion method.
10. Test the effect of vibration and temperature.

An accelerometer measures specific force, and a gyroscope measures
angular velocity. Orientation obtained by integrating gyro measurements
drifts over time. A six-axis IMU does not provide an independently
drift-free absolute heading.

## 5.7 BNO085

**Objective:** Explore inertial measurements and onboard sensor-fusion
outputs.

Experiments:

1.  Verify communication and initialisation.
2.  Identify supported output reports for the selected library and
    firmware.
3.  Log accelerometer and gyroscope readings.
4.  Log the selected rotation/orientation output.
5.  Test each physical axis and verify orientation conventions.
6.  Observe calibration/status indicators.
7.  Hold the device stationary and measure orientation stability.
8.  Compare outputs during controlled rotations.
9.  Evaluate update frequency, timestamps, and dropped reports.
10. Compare the fused output with raw inertial measurements where
    available.

Document the breakout board, interface mode, library, firmware, enabled
reports, and calibration state.

## 5.8 Environmental sensors

For temperature, humidity, pressure, gas, and light sensors, use a
repeatable reference condition and change one variable at a time.

Suggested experiments:

-   Compare readings with a reference instrument.
-   Measure response time after a controlled environmental change.
-   Record stationary noise and long-term drift.
-   Test across the intended operating range.
-   Evaluate warm-up requirements.
-   Document sensor placement and environmental influences.

For gas sensors, follow the manufacturer's warm-up, exposure, and safety
instructions. Do not treat an uncalibrated module's raw ADC value as a
certified gas concentration.

## 5.9 Load cell and HX711

Experiments:

1.  Read unloaded raw ADC values.
2.  Record zero offset and noise.
3.  Apply known reference masses within the load cell's rated capacity.
4.  Fit a calibration factor.
5.  Repeat loading and unloading to evaluate repeatability and
    hysteresis.
6.  Test zero drift over time.
7.  Verify the result using independent reference masses.

## 5.10 Current and voltage sensors

Experiments:

1.  Measure zero-input/zero-current offset where applicable.
2.  Compare voltage readings against a suitable calibrated multimeter.
3.  Compare current readings against a suitable reference meter.
4.  Test multiple operating points within component ratings.
5.  Evaluate noise, offset, scaling, and temperature effects.
6.  Calculate power and compare it with an independent measurement where
    practical.

Observe electrical safety, polarity, isolation, and component ratings.
Do not exceed the module's rated voltage or current.

------------------------------------------------------------------------

# 6. General data analysis

For (N) samples (x_i), calculate:

**Mean**

\[ `\bar`{=tex}{x} = `\frac{1}{N}`{=tex}`\sum`{=tex}\_{i=1}\^{N}x_i \]

**Sample standard deviation**

\[ s = `\sqrt{\frac{1}{N-1}\sum_{i=1}^{N}(x_i-\bar{x})^2}`{=tex} \]

**Absolute error**

\[ e = x\_{`\text{measured}`{=tex}} - x\_{`\text{reference}`{=tex}} \]

**Root mean square error**

\[ RMSE =
`\sqrt{\frac{1}{N}\sum_{i=1}^{N}(x_i-x_{\text{reference},i})^2}`{=tex}
\]

Use only metrics that make sense for the sensor and experiment. Report
sample count, units, reference instrument, and test conditions with
every result.

Suggested general CSV format:

``` csv
timestamp,sensor_model,raw_value,processed_value,reference_value,unit,status,notes
```

Add sensor-specific columns when necessary. For example, IMU logs should
include all axes, while encoder logs should include counts, direction,
and elapsed time.

------------------------------------------------------------------------

# 7. Safety and good experimental practice

-   Read the exact module datasheet before connecting power.
-   Verify supply voltage and logic-level compatibility.
-   Check polarity and pin numbering before powering the circuit.
-   Use current limiting during initial bring-up where practical.
-   Disconnect power before changing wiring.
-   Avoid short circuits and exposed conductors.
-   Do not exceed mechanical, electrical, or environmental ratings.
-   Secure rotating parts and keep hands, wires, and clothing clear.
-   Use suitable protection when testing batteries, motors, high
    currents, or mains-connected equipment.
-   Preserve original raw data; do not overwrite it with filtered or
    calibrated output.
-   Record every hardware or software change that could affect results.

------------------------------------------------------------------------

# 8. Experiment log template

Copy this template into the relevant sensor folder for each experiment.

## Experiment \[ID\] --- \[Sensor model\] --- \[Experiment name\]

### Objective

What property or behaviour is being investigated?

### Hardware

-   Sensor model:
-   Breakout-board revision:
-   Controller:
-   Power supply:
-   Reference instrument:
-   Wiring diagram:

### Software

-   Programming language:
-   IDE / toolchain:
-   Library / driver:
-   Firmware version:
-   Repository commit:

### Setup

Describe the circuit, test arrangement, physical conditions, and
reference measurement.

### Procedure

1.  
2.  
3.  

### Raw data

-   Data file:
-   Number of samples:
-   Sampling interval:
-   Units:

### Results

  Metric                       Result
  ---------------------------- --------
  Mean                         
  Standard deviation           
  Minimum                      
  Maximum                      
  Maximum absolute error       
  Update rate                  
  Dropouts / invalid samples   

### Observations

Describe noise, unexpected readings, environmental effects, and
repeatability.

### Conclusion

-   Status: Pass / Fail / Needs further testing
-   What was learned:
-   Known limitations:
-   Next experiment:

------------------------------------------------------------------------

# 9. Contribution guidelines

When adding a new sensor:

1.  Create a folder under the appropriate category.
2.  Add a sensor-specific `README.md`.
3.  Include the exact sensor and breakout-board model.
4.  Add wiring diagrams and source code.
5.  Explain how to install dependencies and run the experiment.
6.  Include sample raw data where possible.
7.  Document the test setup and reference instrument.
8.  Add measured results; distinguish them from datasheet
    specifications.
9.  Document known limitations and troubleshooting.
10. Update the sensor catalogue in this root README.

### Suggested naming conventions

-   Experiment IDs: `TF-01`, `VL53-02`, `ENC-03`, `MPU-04`.
-   Code: `basic_reading`, `calibration`, `filter_comparison`,
    `accuracy_test`.
-   Data: `YYYY-MM-DD_experiment-condition.csv`.
-   Images: `sensor_model_wiring.png`, `sensor_model_setup.png`.

------------------------------------------------------------------------

## 10. Documentation principles

This repository distinguishes three kinds of information:

1.  **Datasheet specification:** A manufacturer's stated value under
    specified conditions.
2.  **Experimental result:** A value measured using the documented test
    setup.
3.  **Configured value:** A value selected in code, firmware, or a
    software application.

Never present a datasheet specification as if it were measured on the
module being tested. Never add a pin assignment, calibration constant,
or test result without verifying it.

The long-term goal is a well-organised, reproducible sensor
experimentation library that can be used as a reference for embedded
systems, electronics, instrumentation, automation, IoT, and robotics
projects.
