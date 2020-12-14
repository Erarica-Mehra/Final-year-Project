# Final-year-Project
<p> Built an application on Face Recognition system as my major project in 2015 - 2016</p>
<h2> Face Recognition Systems </h2>
<p>Face recognition system is a computer application capable of verifying or
identifying a person from a digital image. One of the ways to do this is to
compare facial features from an image from a database. It is typically used in
security systems and is similar with fingerprint or eye iris recognition system.
Some facial recognition algorithms identify facial features by extracting landmarks, or features, from an image of the subject’s face. For example, an
algorithm may analyze the relative position, size, and/or shape of the eyes,
nose, cheekbones, and jaw. These features are then used to search for other
images with matching features. Other algorithms normalize a gallery of face
images and then compress the face data, only saving the data in the image
that is useful for face recognition. A probe image is then compared with the
face data. </br>
Recognition algorithms can be divided into two main approaches, geometric,
which looks at distinguishing features, or photometric, which is a statistical
approach that distills an image into values and compares the values with
templates to eliminate variances. </br>
Face is a complex multidimensional structure and needs a good computing
techniques for recognition. Our approach treats face recognition as a twodimensional recognition problem. In this scheme face recognition is done
by Principal Component Analysis (PCA). Face images are projected onto a
face space that encodes best variation among known face images. The face
space is defined by eigenface which are eigen vectors of the set of faces, which
may not correspond to general facial features such as eyes, nose, lips. The
eigenface approach uses the PCA for recognition of the images. The system
performs by projecting pre extracted face image onto a set of face space that
represent significant variations among known face images. Face will be categorized as known or unknown face after matching with the present database.
If the user is new to the face recognition system then his/her template will
be stored in the database else matched against the templates stored in the
database. The variable reducing theory of PCA accounts for the smaller face
space than the training set of face.</br> </p>

<h2> Overview</h2>
<p> The scope of the project can be summarized as identifying suspects/criminals and displaying their criminal
records that is name, gender, address, crime detail, punishment and pending cases. It takes input in the form of
image which are captured at real time. The features are
extracted of the captured image and compared against
the extracted features of the images already stored. The
Euclidian Distance is computed and if the difference is
within the threshold value, the image is matched and
results are displayed.</p>

<h2>Built with </h2>
<ol>
<li>C++ </li>
<li>Visual Studio Code </li>

</ol>
<h2>Team</h2>
<ol>
<li>Erarica Mehra </li>
<li>Anand Singh </li>
<li>Saundarya Dorle</li>
</ol>


<h2>Publications</h2>
<ol>
<li>Face Recognition using Principal Component Analysis  -  International Journal of Advanced Technology in Engineering and Science(IJATES) </br>
<link>https://www.ijates.com/images/short_pdf/1459408748_429N.pdf</link>
</li>
<li>Facial Recognition using Perceptual Hash - International Journal of Research in Science and Engineering(IJRISE) </br> </link>https://www.bartleby.com/essay/Web-Application-Based-On-Facial-Recognition-System-FKBC7DLN9BWW</link>
</li>

</ol>
