<?php

require_once('globals.inc');
require_once('config.inc');
require_once('service-utils.inc');
require_once('util.inc');
require_once('system.inc');

function wallguard_install() {
	safe_mkdir("/var/backups/wallguard");
}

function wallguard_deinstall() {
	rmdir_recursive("/var/backups/wallguard");
	unlink_if_exists("/usr/local/etc/rc.d/wallguard.sh");
}

function wallguard_save() {
	global $g;

	$wallguard_config = array();

	foreach(config_get_path("installedpackages/wallguard/config/0", []) as $k => $v) {
		$wallguard_config[$k] = addslashes($v);
	}

	if ($wallguard_config["enable"] != "on") {
		if (is_service_running("wallguard")) {
			stop_service("wallguard");
		}

		unlink_if_exists("/usr/local/etc/rc.d/wallguard.sh");
		return;
	}

	$pidfile = "{$g['varrun_path']}/wallguard.pid";

	$addr = $wallguard_config["server_addr"];
	$port = $wallguard_config["server_port"];
	$appi = $wallguard_config["app_id"];
	$apps = $wallguard_config["app_secret"];

	$tunnel_addr = $wallguard_config["tunnel_addr"];
	$tunnel_port = $wallguard_config["tunnel_port"];

	$version = trim(shell_exec("cat /etc/version"));
	$uuid = trim(shell_exec("dmidecode -s system-uuid"));

	write_rcfile(array(
		"file" => "wallguard.sh",
		"stop" => "/bin/kill `/bin/cat {$pidfile}`",
		"start" => "/usr/sbin/daemon -cP {$pidfile} /usr/local/bin/wallguard --addr={$addr} --port={$port} --app_id={$appi} --app_secret={$apps} --uuid={$uuid} --version={$version} --tunnel-addr={$tunnel_addr} --tunnel-port={$tunnel_port}"
	));

	if (is_service_running("wallguard")) {
		restart_service("wallguard");
	} else {
		start_service("wallguard");
	}
}

function wallguard_validate_input($post, &$input_errors) {
	# Validation is done here
}

?>
