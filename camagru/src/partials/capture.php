<div class="capture">
    <section id="capture-new">
        <form action="capture.php" method="post" enctype="multipart/form-data" flex flex-center-content>
            <div flex="1" flex-col>
                <div class="header">Capture</div>
                <div flex flex-col flex-center-items>
                    <div id="capture-preview">
                        <img alt="background" id="background">
                        <img alt="overlay" id="overlay">
                    </div>

                    <div id="capture-controls">
                        <div>
                            <input type="hidden" name="MAX_FILE_SIZE" value="2097152">
                            <label for="background-input">Background:</label>
                            <input type="file" id="background-input" name="background">

                            <label for="overlay-input">Overlay:</label>
                            <input type="file" id="overlay-input" name="overlay">

                            <input type="hidden" id="overlay-path" name="overlay_path">
                        </div>

                        <div flex flex-col>
                            <div>
                                <label for="overlay-x">Overlay X: </label>
                                <input type="number" id="overlay-x" name="overlay_x">
                            </div>

                            <div>
                                <label for="overlay-y">Overlay Y: </label>
                                <input type="number" id="overlay-y" name="overlay_y">
                            </div>
                        </div>
                    </div>
                
                    <div id="submit-wrapper">
                        <a href="webcam.php"> Use webcam</a>
                    </div>
                    <div id="submit-wrapper">
                        <button name="submit" type="submit" name="submit" value="true">Save image</button>
                    </div>
                </div>
            </div>
            <div flex="1" flex-col>
                <div class="header">Available overlays</div>
                <div flex-col flex-center-items>
                    <div class="thumbnail-small">
                        <img src="../assets/mario.png" alt="mario">
                    </div>
                    <div class="thumbnail-small">
                        <img src="../assets/deal-with-it.png" alt="thug">
                    </div>
                    <div class="thumbnail-small">
                        <img src="../assets/pikachu.png" alt="pikachu">
                    </div>
                    <div class="thumbnail-small">
                        <img src="../assets/rick.png" alt="rick">
                    </div>
                    <div class="thumbnail-small">
                        <img src="../assets/cat.png" alt="cat">
                    </div>
                </div>
            </div>
        </form>
    </section>

    <section id="capture-history">
        <div flex="1" flex-col>
            <div class="header">History</div>
            <div flex flex-col flex-center-items>
                <?php echo $history ?>
            </div>
        </div>
    </section>
</div>

<script src="../assets/capture.js"></script>