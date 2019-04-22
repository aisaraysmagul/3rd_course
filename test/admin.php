<?php
session_start();
    $con=oci_connect("Akzharkyn2","project","localhost/orcl");
    if (!$con)
        echo 'Failed to connect to Oracle';
    else{
      $student = $_POST['student'];
      if ($student==null){
        $stu=0;
      }
      else{
        $stu=1;
      }
      if ($stu){
        $query = "SELECT * from Lib_User where username=:usr and password=:pwd and isStudent=:stu";
        $stid = oci_parse($con, $query);
        if (isset($_POST['username']) || isset($_POST['password'])){           
          $user = $_POST['username'];
          $pass = $_POST['password'];
        }
        oci_bind_by_name($stid, ':usr', $user);
        oci_bind_by_name($stid, ':pwd', $pass);
        oci_bind_by_name($stid, ':stu', $stu);
        oci_execute($stid);
        $row = oci_fetch_array($stid, OCI_ASSOC);
        if ($row) {
            echo  '<script language="javascript">';  
            echo  'alert("You are successfully logged!" );';  
            echo    ' window.location="square/student.html";';  
            echo  '</script>'; 
            }
        else{
            echo  '<script language="javascript">';  
            echo  'alert("Wrong Username or Password" );';  
            echo    ' window.location="login.html";';  
            echo  '</script>'; 

            exit;
        }
      }else{
        $query = "SELECT * from Lib_User where username=:usr and password=:pwd and isStudent=:stu";
        $stid = oci_parse($con, $query);
        if (isset($_POST['username']) ||isset($_POST['password'])){           
          $user = $_POST['username'];
          $pass=$_POST['password'];
        }
        oci_bind_by_name($stid, ':usr', $user);
        oci_bind_by_name($stid, ':pwd', $pass);
        oci_bind_by_name($stid, ':stu', $stu);
        oci_execute($stid);
        $row = oci_fetch_array($stid, OCI_ASSOC);
        if ($row) {
           $_SESSION['login']=$_POST['username'];
           echo"log in successful";
           // header('location: square/employee.html');
            }
           else {
          echo("The person " . $user . " is not found .
          Please check the spelling and try again or check password");
          exit;
          }
      }
    }
?>