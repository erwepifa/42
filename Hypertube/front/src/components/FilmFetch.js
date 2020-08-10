import React, { useState } from 'react';
import { API_ENDPOINT } from "../constant";
import FilmInfo from "./FilmInfo";
import Grid from "@material-ui/core/Grid";
import FilmPlayer from "./FilmPlayer";
import FilmComments from "./FilmComments";

export default function FilmFetch(props) {

    const [movieInfo, setMovieInfo] = useState({ id: null });
    function getFilmInfo() {
        fetch(`${API_ENDPOINT}/movie/information/${props.id}`, {
            credentials: "include",
            headers: {
                Accept: "application/json",
                "Content-Type": "application/json"
            },
            method: "GET"
        })
            .then(res => res.json())
            .then(res => {
                setMovieInfo(res);
            });
        fetch(`${API_ENDPOINT}/movie/isee/${props.id}`, {
            credentials: "include",
            headers: {
                Accept: "application/json",
                "Content-Type": "application/json"
            },
            method: "GET"
        });
    }
    if (movieInfo.id === undefined || movieInfo.id === null) {
        getFilmInfo();
    }

    // getFilmInfo();
    return (
        <Grid
            container
            direction="column"
            justify="flex-start"
            alignItems="stretch"
            spacing={4}
        >
            <FilmInfo movieInfo={{ ...movieInfo }} />
            <Grid item>
                <FilmPlayer id={props.id} imdbId={movieInfo.imdbId} />
            </Grid>
            <Grid item>
                <FilmComments id={props.id} />
            </Grid>
        </Grid>
    )

}