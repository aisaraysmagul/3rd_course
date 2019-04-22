<?php
session_start();
    $con=oci_connect("Akzharkyn2","project","localhost/orcl");
    if (!$con) echo 'Failed to connect to Oracle';
    else{
	    $isbn = $_POST['isbn'];
	    $date = $_POST['date'];
	    $id = $_POST['student'];

	    $query = "SELECT BookID from Book where BookISBN = :isbn";
	    $st = oci_parse($con, $query);
	    oci_bind_by_name($st, ':isbn', $isbn);
        oci_execute($st);
        $bookId = oci_fetch_array($st, OCI_ASSOC);
        
        $que = "INSERT INTO Rent (BookID, RentDate, StudentID) values (:book, TO_DATE(:dates, 'dd/mm/yyyy'), :id)";
        $st1 = oci_parse($con, $que);
        $a = intval($bookId['BOOKID']);

        $d = date('d/m/Y', strtotime($date));
        $e = intval($id);
        $c = strval($date);

        oci_bind_by_name($st1, ':book', $a);
        oci_bind_by_name($st1, ':dates', $c);
        oci_bind_by_name($st1, ':id', $e);
        $res = oci_execute($st1);
        if($res){
            $_SESSION['RedirectKe'] = $_SERVER['REQUEST_URI'];
            header('location: square/employee.html');
        }

    }
?>