<?php

  $pin = $_GET['pin'];
  $state = $_GET['state'];

  // Create cURL call
  $service_url = 'http://192.168.8.101/digital/' . $pin . '/' . $state;
  $curl = curl_init($service_url);
   
  // Send cURL to Yun board
  curl_setopt($curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4 ); 
  $curl_response = curl_exec($curl);
  curl_close($curl);

  //Print answer
  echo $curl_response;

?>