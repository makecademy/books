<?php

	// Store data
    if ($_GET["temp"] && $_GET["hum"]) {

    	$string = file_get_contents("state.json");
    	$json_a = json_decode($string,true);

    	$json_a['temperature'] = $_GET["temp"];
        $json_a['humidity'] = $_GET["hum"];
		 
	    $fp = fopen('state.json', 'w');
	    fwrite($fp, json_encode($json_a));
    	fclose($fp);
    }

?>