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
      $query = "SELECT bookName, AuthorName from eBooks join Book on eBooks.BookID = Book.BookID join Author on Book.AuthorID = Author.AuthorID";
      $state = oci_parse($con, $query);
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
                   </div>
                </div>');
   }
?>
</section>
  
  <div id="ftco-loader" class="show fullscreen"><svg class="circular" width="48px" height="48px"><circle class="path-bg" cx="24" cy="24" r="22" fill="none" stroke-width="4" stroke="#eeeeee"/><circle class="path" cx="24" cy="24" r="22" fill="none" stroke-width="4" stroke-miterlimit="10" stroke="#F96D00"/></svg></div>


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