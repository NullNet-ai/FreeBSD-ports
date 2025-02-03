<?php

global $priv_list;

$priv_list['page-services-wallguard'] = array();
$priv_list['page-services-wallguard']['name'] = "WebCfg - Services: WallGuard";
$priv_list['page-services-wallguard']['descr'] = "Allow access to WallGuard package GUI";

$priv_list['page-services-wallguard']['match'] = array();
$priv_list['page-services-wallguard']['match'][] = "pkg_edit.php?xml=wallguard.xml";  
