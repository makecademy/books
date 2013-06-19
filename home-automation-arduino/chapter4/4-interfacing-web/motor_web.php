<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Remote control</title>
  <script type="text/javascript" src="script.js"></script>
</head>
<body>

<form id="speedForm" action="remote_control.php" method="GET">
    <span style="font-size:40px;">Motor speed: </span><input type="text" name="speed" style="font-size: 40px;" id="speedText">
    <input type="button" id="submitButton" style="border:1px solid #000; font-size:40px;" value="submit" onClick="sendCommand()"/>
</form>

<?php 

$speed = $_GET["speed"]; 
$myFile = "motorCommand.txt";
$fh = fopen($myFile, 'w') or die("can't open file");
fwrite($fh, $speed);
fclose($fh);

?>

<?php

	$myFile = "sensorValue.txt";
	$fh = fopen($myFile, 'r') or die("can't open file");
	$sensorValue = fread($fh, $speed);
	fclose($fh);

	echo "<span style='font-size:40px;'>Analog sensor value: ";
	echo $sensorValue;
	echo "</span>";

?>

</body>
</html>