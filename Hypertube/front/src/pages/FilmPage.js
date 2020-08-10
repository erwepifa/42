import React from "react";
import NavBar from "../components/NavBar";
import Container from "@material-ui/core/Container";

import Footer from "../components/Footer";
import Box from "@material-ui/core/Box";
import FilmFetch from "../components/FilmFetch";

const FilmPage = props => {
  // const [movieInfo, setMovieInfo] = useState({ id: null });
  // function getFilmInfo() {
  //   fetch(`${API_ENDPOINT}/movie/information/${props.match.params.id}`, {
  //     credentials: "include",
  //     headers: {
  //       Accept: "application/json",
  //       "Content-Type": "application/json"
  //     },
  //     method: "GET"
  //   })
  //     .then(res => res.json())
  //     .then(res => {
  //       setMovieInfo(res);
  //     });
  //   fetch(`${API_ENDPOINT}/movie/isee/${props.match.params.id}`, {
  //     credentials: "include",
  //     headers: {
  //       Accept: "application/json",
  //       "Content-Type": "application/json"
  //     },
  //     method: "GET"
  //   });
  // }
  // if (movieInfo.id === undefined || movieInfo.id === null) getFilmInfo();

  return (
    <div>
      <NavBar />
      <Container component="main">
        <FilmFetch id={props.match.params.id} />

      </Container>
      <Box mt={5}>
        <Footer />
      </Box>
    </div>
  );
};

export default FilmPage;
