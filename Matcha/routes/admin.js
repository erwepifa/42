const path = require('path');

const express = require('express');

////Requiring Controller
const adminController = require('../controllers/admin');

const router = express.Router();

// GET ADMIN PAGE
router.get('/admin', adminController.getIndex);
/// SEARCH USER
router.post('/admin/user', adminController.postSearch);
//// DELETE USER
router.get('/admin/delete/:id', adminController.getDel);
//// REPORTED LOGS
router.get('/admin/reported', adminController.getReported);
router.post('/admin/reported', adminController.postReported);

module.exports = router;