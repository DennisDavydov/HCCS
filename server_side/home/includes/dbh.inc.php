<?php 

$dbServername = "localhost";
$dbUsername = "phpmyadmin";
$dbPassword = "password";
$daName = "node_data";

$conn = mysqli_connect($dbServername, $dbUsername, $dbPassword, $daName);

if ($conn->connect_error) {
	die("Connection failed!");
}