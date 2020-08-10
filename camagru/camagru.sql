-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le :  mer. 22 jan. 2020 à 04:55
-- Version du serveur :  5.6.43
-- Version de PHP :  5.6.40

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `camagru`
--

-- --------------------------------------------------------

--
-- Structure de la table `picture`
--

CREATE TABLE `picture` (
  `filename` varchar(255) NOT NULL,
  `userId` int(11) NOT NULL,
  `creationDate` datetime NOT NULL,
  `id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `picturecomment`
--

CREATE TABLE `picturecomment` (
  `id` int(11) NOT NULL,
  `content` text NOT NULL,
  `userId` int(11) NOT NULL,
  `pictureId` int(11) NOT NULL,
  `creationDate` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `picturecomment`
--

INSERT INTO `picturecomment` (`id`, `content`, `userId`, `pictureId`, `creationDate`) VALUES
(2, 'test', 5, 3, '2020-01-21 11:59:27'),
(3, '<script>alert(\'Il y a une faille XSS\')</script>', 5, 3, '2020-01-21 12:02:10'),
(4, 'fhfgdhgfhfghgdf\r\n', 5, 1, '2020-01-21 15:06:21'),
(5, '<script>alert(\'Il y a une faille XSS\')</script>', 5, 2, '2020-01-21 15:07:05'),
(6, 'test', 8, 2, '2020-01-22 12:53:11');

-- --------------------------------------------------------

--
-- Structure de la table `picturelike`
--

CREATE TABLE `picturelike` (
  `id` int(11) NOT NULL,
  `userId` int(11) NOT NULL,
  `pictureId` int(11) NOT NULL,
  `creationDate` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `login` varchar(42) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `email` varchar(100) NOT NULL,
  `confirmationCode` varchar(255) NOT NULL,
  `active` tinyint(1) NOT NULL DEFAULT '0',
  `resetPassword` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `picture`
--
ALTER TABLE `picture`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `picturecomment`
--
ALTER TABLE `picturecomment`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `picturelike`
--
ALTER TABLE `picturelike`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `email` (`email`),
  ADD UNIQUE KEY `login` (`login`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `picture`
--
ALTER TABLE `picture`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `picturecomment`
--
ALTER TABLE `picturecomment`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT pour la table `picturelike`
--
ALTER TABLE `picturelike`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT pour la table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
