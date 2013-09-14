<?php 

$db = new SQLite3('test.db');

$results = $db->query('SELECT Measurement, Temperature FROM Temperatures');
$i = 0;
while($row = $results->fetchArray())
{
    $i++;
    $dataset[] = array($row['Measurement'],$row['Temperature']);
}

echo json_encode($dataset);

?>