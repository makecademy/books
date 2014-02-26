<?php

	// Load JSON state
    $string = file_get_contents("robot_state.json");
    $json_a = json_decode($string,true);

    if($_GET["display"] == "temp") {
    	echo "Temperature: " . $json_a["temperature"];
    }

    if($_GET["display"] == "hum") {
		echo "Humidity: " . $json_a["humidity"];
    }

?>