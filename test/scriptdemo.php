<html>
<head><title>Oracle demo</title></head>
<body>
    <?php 
    session_start();
    $conn=oci_connect("Akzharkyn2","project","localhost/orcl");
    If (!$conn)
        echo 'Failed to connect to Oracle';
    else{
        $username = $_POST['username'];
    	$password = $_POST['pass'];
    	$faculty = $_POST['faculty'];
    	$gender = $_POST['gender'];
    	$email = $_POST['email'];
    	$reg_no = $_POST['reg_no'];
    	$student = $_POST['student'];
    	$cont_no = $_POST['contact_no'];
    	$first = $_POST['firstname'];
    	$last = $_POST['lastname'];
    	
    	if ($student==null){
    		$stu=0;
    	}else{
    		$stu=1;
    	}
    	if($stu){
    		$studId = $_POST['studentId'];
    		$stid = oci_parse($conn, 'INSERT INTO Lib_User (UserID, first_name, last_name, gender, email, contact_no, username, password, registration_no, FacultyID, isStudent) VALUES(:Id, :myfirst, :mylast, :mygen, :myemail, :mycont, :myuser, :mypass, :myreg, :myfac, :mystu)');

    		oci_bind_by_name($stid, ':Id', $studId);
			oci_bind_by_name($stid, ':myfirst', $first);
			oci_bind_by_name($stid, ':mylast', $last);
			oci_bind_by_name($stid, ':mygen', $gender);
			oci_bind_by_name($stid, ':myemail', $email);
			oci_bind_by_name($stid, ':mycont', $cont_no);
			oci_bind_by_name($stid, ':myuser', $username);
			oci_bind_by_name($stid, ':mypass', $password);
			oci_bind_by_name($stid, ':myreg', $reg_no);
			oci_bind_by_name($stid, ':myfac', $faculty);
			oci_bind_by_name($stid, ':mystu', $stu);
			

			$row = oci_fetch_array($stid, OCI_ASSOC);
			if (oci_execute($stid)) {
	            echo  '<script language="javascript">';  
	            echo  'alert("You are successfully registered!" );';  
	            echo    ' window.location="square/student.html";';  
	            echo  '</script>'; 
	            }
	        else{
	            echo  '<script language="javascript">';  
	            echo  'alert("You did not fill some blanks" );';  
	            echo    ' window.location="index.html";';  
	            echo  '</script>'; 

	            exit;
	        }

			
    	}else{
    		$stid = oci_parse($conn, 'INSERT INTO Lib_User (first_name, last_name, gender, email, contact_no, username, password, registration_no, FacultyID, isStudent) VALUES(:myfirst, :mylast, :mygen, :myemail, :mycont, :myuser, :mypass, :myreg, :myfac, :mystu)');

			oci_bind_by_name($stid, ':myfirst', $first);
			oci_bind_by_name($stid, ':mylast', $last);
			oci_bind_by_name($stid, ':mygen', $gender);
			oci_bind_by_name($stid, ':myemail', $email);
			oci_bind_by_name($stid, ':mycont', $cont_no);
			oci_bind_by_name($stid, ':myuser', $username);
			oci_bind_by_name($stid, ':mypass', $password);
			oci_bind_by_name($stid, ':myreg', $reg_no);
			oci_bind_by_name($stid, ':myfac', $faculty);
			oci_bind_by_name($stid, ':mystu', $stu);

			if (oci_execute($stid)) {
	            echo  '<script language="javascript">';  
	            echo  'alert("You are successfully registered!" );';  
	            echo    ' window.location="square/employee.html";';  
	            echo  '</script>'; 
	            }
	        else{
	            echo  '<script language="javascript">';  
	            echo  'alert("You did not fill some blanks" );';  
	            echo    ' window.location="index.html";';  
	            echo  '</script>'; 

	            exit;
	        }
    	}
    	
    	
	}
	oci_close($conn);
?>
 
</body>
</html>
