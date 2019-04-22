<?php
    session_start();
    $con=oci_connect("Akzharkyn2","project","localhost/orcl");
    if (!$con) echo 'Failed to connect to Oracle';
    else{
	    $isbn = $_POST['ISBN'];
	    $name = $_POST['name'];
	    $type = $_POST['typeBook'];
	    $author = $_POST['author'];
	    $publ = $_POST['publisher'];
	    $lang = $_POST['language'];
	    $category = $_POST['category'];
	    $fac = $_POST['faculty'];


	    $q_author = "SELECT * from Author where AuthorName=:auth";
	    $state_a= oci_parse($con, $q_author);
	    oci_bind_by_name($state_a, ':auth', $author);
        oci_execute($state_a);
        $s1 = oci_fetch_array($state_a);
        if ($s1==null){
            $query = "INSERT INTO Author (AuthorName) values (:aut)";
            $st= oci_parse($con, $query);
            oci_bind_by_name($st, ':aut', $author);
            oci_execute($st);
        }
        oci_execute($state_a);
        $s1 = oci_fetch_array($state_a);
        $authorID = $s1['AUTHORID'];


        $q_cat = "SELECT * from Categories where CategoryName=:cat";
	    $state_c= oci_parse($con, $q_cat);
	    oci_bind_by_name($state_c, ':cat', $category);
        oci_execute($state_c);
        $s2 = oci_fetch_array($state_c);
        if ($s2==null){
            $query = "INSERT INTO Categories (CategoryName) values (:cat)";
            $st= oci_parse($con, $query);
            oci_bind_by_name($st, ':cat', $category);
            oci_execute($st);
        }

        oci_execute($state_c);
        $s2 = oci_fetch_array($state_c);
        $catID = $s2['CATEGORYID'];

        
        $q_lang = "SELECT * from Languages where LangName=:lang";
	    $state_l = oci_parse($con, $q_lang);
	    oci_bind_by_name($state_l, ':lang', $lang);
        oci_execute($state_l);
        $s3 = oci_fetch_array($state_l);
        if ($s3==null){
            $query = "INSERT INTO Languages (LangName) values (:lan)";
            $st= oci_parse($con, $query);
            oci_bind_by_name($st, ':lan', $lang);
            oci_execute($st);
        }
        oci_execute($state_l);
        $s3 = oci_fetch_array($state_l);
        $langID = $s3['LANGID'];


        $q_publish = "SELECT * from Publish where PublishName=:publish";
	    $state_p= oci_parse($con, $q_publish);
	    oci_bind_by_name($state_p, ':publish', $publ);
        oci_execute($state_p);
        $s4 = oci_fetch_array($state_p);
        if ($s4==null){
            $query = "INSERT INTO Publish (PublishName) values (:pub)";
            $st= oci_parse($con, $query);
            oci_bind_by_name($st, ':pub', $publ);
            oci_execute($st);
            
        }
        oci_execute($state_p);
        $s4 = oci_fetch_array($state_p);
        $publID = $s4['PUBLISHID'];


        $stid = oci_parse($con, 'SELECT bookName, AuthorName from eBooks join Book on eBooks.BookID = Book.BookID join Author on Book.AuthorID = Author.AuthorID');
        $res = oci_execute($stid);
        $row = oci_fetch_array($stid);
        print_r($row[1]);


        echo $type;
        if ($authorID!=null and $publID!=null and $langID!=null and $catID!=null and $isbn!=null and $fac!=null and $name!=null){
      
            $que = "INSERT INTO Book (bookISBN, TypeBookID, AuthorID, PublishID, LangID, CategoryID, FacultyID, bookName) values (:isbn, :type, :aut, :pub, :la, :cat, :fac, :name)";
     
            $state = oci_parse($con, $que);
            $b = intval($type);
            $c = intval($authorID);
            $d = intval($publID);
            $e = intval($langID);
            $f = intval($catID);
            $h = intval($fac);
            oci_bind_by_name($state, ':isbn', $isbn);
            oci_bind_by_name($state, ':type', $b);
            oci_bind_by_name($state, ':aut', $c);
            oci_bind_by_name($state, ':pub', $d);
            oci_bind_by_name($state, ':la', $e);
            oci_bind_by_name($state, ':cat', $f);
            oci_bind_by_name($state, ':fac', $h);
            oci_bind_by_name($state, ':name', $name);
          
            $result = oci_execute($state);
           
                // Query successfully executed
            if (oci_execute($stid)) {
                echo  '<script language="javascript">';  
                echo  'alert("You are successfully add a Book!" );';  
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
             
            $ebook = $_POST['ebook'];
            if ($ebook != null){
                $query = "SELECT BookID from Book where BookISBN = :isbn";
                $st = oci_parse($con, $query);
                oci_bind_by_name($st, ':isbn', $isbn);
                oci_execute($st);
                $bookId = oci_fetch_array($st, OCI_ASSOC);

                $extension = $_POST['extension'];
                $que = "INSERT into eBooks(BookID, extension) values (:book, :ext)";
                $st1 = oci_parse($con, $que);
                $a = intval($bookId);

                oci_bind_by_name($st1, ':book', $a);
                oci_bind_by_name($st1, ':ext', $extension);
                oci_execute($st1);

            $state = oci_parse($con, $que);
            }

        }
        else{
            echo "Please check all rows";
        }

	}
    oci_close($con);
?>