<?php
    header('content-type: text/xml');
    $url = 'http://xoap.weather.com/search/search?' . $_SERVER["QUERY_STRING"];
    echo file_get_contents($url);
?>