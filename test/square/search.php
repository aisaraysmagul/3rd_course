<!DOCTYPE html>
<html lang="en">
  <head>
    <title>Online Library</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    
    <link href="https://fonts.googleapis.com/css?family=Rubik:300,400,500,700,900" rel="stylesheet">

    <link rel="stylesheet" href="css/open-iconic-bootstrap.min.css">
    <link rel="stylesheet" href="css/animate.css">
    
    <link rel="stylesheet" href="css/owl.carousel.min.css">
    <link rel="stylesheet" href="css/owl.theme.default.min.css">
    <link rel="stylesheet" href="css/magnific-popup.css">

    <link rel="stylesheet" href="css/aos.css">

    <link rel="stylesheet" href="css/ionicons.min.css">
    
    <link rel="stylesheet" href="css/flaticon.css">
    <link rel="stylesheet" href="css/icomoon.css">
    <link rel="stylesheet" href="css/style.css">
  </head>
  <body>
	  
    <nav class="navbar navbar-expand-lg navbar-dark ftco_navbar bg-dark ftco-navbar-light" id="ftco-navbar">
	    <div class="container">
	      <a class="navbar-brand" href="index.html"><span>Lib.</span></a>
	      <button class="navbar-toggler js-fh5co-nav-toggle fh5co-nav-toggle" type="button" data-toggle="collapse" data-target="#ftco-nav" aria-controls="ftco-nav" aria-expanded="false" aria-label="Toggle navigation">
	        <span class="oi oi-menu"></span> Menu
	      </button>

	      <div class="collapse navbar-collapse" id="ftco-nav">
	        <ul class="navbar-nav nav ml-auto">
	          <li class="nav-item"><a href="/test/square/student.html" class="nav-link" data-nav-section="home"><span>Home</span></a></li>
	          <li class="nav-item"><a href="https://my.sdu.edu.kz/loginAuth.php" class="nav-link">Student's Portal</a></li>
	        </ul>
	      </div>
	    </div>
	  </nav>
    
    <section class="hero-wrap js-fullheight" style="background-image: url('images/sdu.jpg');" data-section="home"> 
      <div class="container">
        <div class="row no-gutters slider-text js-fullheight align-items-center justify-content-start" data-scrollax-parent="true">
          <div class="col-md-8 ftco-animate mt-5" data-scrollax=" properties: { translateY: '70%' }" style="background-color: rgba(232, 237, 244, 0.7); margin: 0 0 10px; padding: 10px; ">
          	<p class="d-flex align-items-center" data-scrollax="properties: { translateY: '30%', opacity: 1.6 }"></p>
            <h1 class="mb-4" data-scrollax="properties: { translateY: '30%', opacity: 1.6 }" style="color:black;">Welcome to the Online Library</h1>
            <p class="mb-4" data-scrollax="properties: { translateY: '30%', opacity: 1.6 }" style="color:black;">A service dedicated to students of the Suleyman Demirel University. We provide online resources, professional support and guidance to all our students whenever, and from wherever they have chosen to study.</p>
          </div>
        </div>
      </div>
    </section>
		
		<section class="ftco-section ftco-services ftco-no-pt">

<?php
session_start();
    $con=oci_connect("Akzharkyn2","project","localhost/orcl");
    if (!$con) echo 'Failed to connect to Oracle';
    else{
      if (isset($_POST['what']) and isset($_POST['faculty'])){
  	    $name = $_POST['what'];
  	    $faculty = $_POST['faculty'];

  	    $query = "SELECT bookName, AuthorName from Book join Author on Book.AuthorID = Author.AuthorID where bookName=:name and FacultyID=:fac";
  	    $state = oci_parse($con, $query);
  	    $a = intval($faculty);
  	    oci_bind_by_name($state, ':name', $name);
  	    oci_bind_by_name($state, ':fac', $a);
        oci_execute($state);
        $row = oci_fetch_array($state, OCI_ASSOC);
       	echo('<div class="container">
       			        <div class="row services-section">
       			          <div class="col-md-4 d-flex align-self-stretch ftco-animate">
       			            <div class="media block-6 services text-center d-block">
       			              <div class="icon"><span class="flaticon-layers"></span></div>
       			              <div class="media-body">
       			                <h3 class="heading mb-3">'.$row['BOOKNAME'].'</h3>
       			                <p>'.$row['AUTHORNAME'].'</p>
       			              </div>
       			            </div>      
       			          </div>
       			         </div>');
       }
      else{ 
        
        $st = oci_parse($con, 'SELECT BookID, BookISBN, AuthorName, TypeBookID, PublishName, LangName, CategoryName, FacultyID, bookName from Book join Author on Book.AuthorID = Author.AuthorID join Publish on Book.PublishID = Publish.PublishID join Languages on Book.LangID = Languages.LangID join Categories on Book.CategoryID = Categories.CategoryID');
        oci_execute($st);
        oci_fetch_all($st, $rows);
        $num_row = count($rows['BOOKID']);
        echo '<h1> You have '.$num_row.' books in your database</h1>
          <table class="table table-striped table-bordered table-sm" id="myTable2">
                <thead class="thead-dark">
                  <tr>
                    <th scope="col">#</th>
                    <th scope="col">BookID</th>
                    <th scope="col">ISBN</th>
                    <th scope="col">TypeBookID</th>
                    <th scope="col">AuthorID</th>
                    <th scope="col">PublishID</th>
                    <th scope="col">LangID</th>
                    <th scope="col">CategoryID</th>
                    <th scope="col">FacultyID</th>
                    <th onclick="sortTable()" scope="col">Name of Book</th>
                  </tr>
                </thead>
                <tbody>';
        for($i = 0; $i<$num_row; $i++){
          echo '<tr><th scope="row">'.($i+1).'</th>
                      <td>'.$rows['BOOKID'][$i].'</td>
                      <td>'.$rows['BOOKISBN'][$i].'</td>
                      <td>'.$rows['TYPEBOOKID'][$i].'</td>
                      <td>'.$rows['AUTHORNAME'][$i].'</td>
                      <td>'.$rows['PUBLISHNAME'][$i].'</td>
                      <td>'.$rows['LANGNAME'][$i].'</td>
                      <td>'.$rows['CATEGORYNAME'][$i].'</td>
                      <td>'.$rows['FACULTYID'][$i].'</td>
                      <td>'.$rows['BOOKNAME'][$i].'</td>
                      </tr>';
        }
        echo '</tbody></table>
        <button onclick="sortTable()">Sort</button>';
      }
		 

	 }
?>
</section>
	
  <div id="ftco-loader" class="show fullscreen"><svg class="circular" width="48px" height="48px"><circle class="path-bg" cx="24" cy="24" r="22" fill="none" stroke-width="4" stroke="#eeeeee"/><circle class="path" cx="24" cy="24" r="22" fill="none" stroke-width="4" stroke-miterlimit="10" stroke="#F96D00"/></svg></div>


<script>
  function sortTable() {
  var table, rows, switching, i, x, y, shouldSwitch;
  table = document.getElementById("myTable2");
  switching = true;
  /* Make a loop that will continue until
  no switching has been done: */
  while (switching) {
    // Start by saying: no switching is done:
    switching = false;
    rows = table.rows;
    /* Loop through all table rows (except the
    first, which contains table headers): */
    for (i = 1; i < (rows.length - 1); i++) {
      // Start by saying there should be no switching:
      shouldSwitch = false;
      /* Get the two elements you want to compare,
      one from current row and one from the next: */
      x = rows[i].getElementsByTagName("TD")[0];
      y = rows[i + 1].getElementsByTagName("TD")[0];
      // Check if the two rows should switch place:
      if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
        // If so, mark as a switch and break the loop:
        shouldSwitch = true;
        break;
      }
    }
    if (shouldSwitch) {
      /* If a switch has been marked, make the switch
      and mark that a switch has been done: */
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
    }
  }
}
  
  </script>

  <script src="js/jquery.min.js"></script>
  <script src="js/jquery-migrate-3.0.1.min.js"></script>
  <script src="js/popper.min.js"></script>
  <script src="js/bootstrap.min.js"></script>
  <script src="js/jquery.easing.1.3.js"></script>
  <script src="js/jquery.waypoints.min.js"></script>
  <script src="js/jquery.stellar.min.js"></script>
  <script src="js/owl.carousel.min.js"></script>
  <script src="js/jquery.magnific-popup.min.js"></script>
  <script src="js/aos.js"></script>
  <script src="js/jquery.animateNumber.min.js"></script>
  <script src="js/scrollax.min.js"></script>
  <script src="js/main.js"></script>
    
  </body>
</html>