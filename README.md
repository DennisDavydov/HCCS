# HCCS (HomeClimateControlSystem)

### Made by: [Denis Davydov](https://github.com/DennisDavydov) 
> With a contribution of [Vasily Davydov](https://github.com/vas-dav)

# Introduction:

### This project's aim is to create an IoT heater control system that is accessible through a website. For this project, the website will be hosted on a Raspberry Pi server only accessible from inside the local network, but it can be as easily hosted on a rented web server.

#### Required materials:

- Raspberry Pi * 1
- NodeMCU * 1x
- DHT11(or equivalent) * 1x
- 5v RelayModule * 1x

> Where x is the number of heaters you need controlled.

### Operation:

After setting up the server, installing each nodeMCU module to the corresponding heater and connecting all to the local wifi the user may access the website by calling to the raspberry pi in a web browser.  They will be presented with a form that asks them the requested temperature and shows them the current temperature of each heater. After clicking 'submit' the nodes will turn the heaters off if the temperature is above requested and turn them on otherwise.

#### Deconstruction:
The project consists of four parts:
- 1.Actual wiring of the nodeMCU control module
	Refer to wiring.pdf
- 2.NodeMCU software to make requests to server.
	Refer to IoT_sensor.ino
- 3.User-side website.
	Refer to index.php inside the 'home' folder
- 4.Server-side php files handling requests.
	Handled by all the files inside 'includes' folder

> Technically, there is also the step of setting up Raspberry Pi OS and server, but since the use of RaPi is a personal preference and pretty > straightforward anyway I do not include it.
