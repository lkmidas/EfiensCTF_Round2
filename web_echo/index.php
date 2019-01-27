<?php 

    ini_set('display_errors', 'on'); 
    ini_set('error_reporting', E_ALL ^ E_DEPRECATED); 

    function f10eq($string = '.') { 
        return scandir($string); 
    } 
     
    if (isset($_GET['echo']) && !empty($_GET['echo'])) { 
         
        $code = $_GET['echo']; 
        $function_internal = get_defined_functions()['internal']; 
        $extra_function = array ('eval', 'include', 'require', 'function'); 
        $special_chr = array ('\.', '\+', '\-', '\*', '\"', '\`', '\[', '\]', '\%', '\'', '\_'); 
        $blacklist_array = array_merge($function_internal, $extra_function, $special_chr); 
         
        foreach ($blacklist_array as $item) { 
            if (preg_match ('/' . $item . '/im', $code)) { 
                die('Die, die, die!'); 
            } 
        } 
         
        eval('echo('.$code.');'); 
         
    } else { 
        show_source(f10eq()[3]); 
    } 

?>
