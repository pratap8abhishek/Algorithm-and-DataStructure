// How do you schedule a job (e.g., sending emails daily at 9 AM)?

const cron = require('node-cron');
const nodemailer = require('noadmailer');

async function sendEmails() {
    // Setup transporter
    const transporter = nodemailer.createTransport({
      service: 'gmail', // or use smtp details
      auth: {
        user: 'myemail@gmail.com',
        pass: 'generated_app_password',
      },
    });
  
    // Email options
    const mailOptions = {
      from: 'myemail@gmail.com',
      to: 'recipient@example.com', // can be multiple emails separated by commas
      subject: 'Daily Update',
      text: 'Hello! This is your 9 AM daily update.',
    };
  
    // Send the email
    try {
      const info = await transporter.sendMail(mailOptions);
      console.log('Email sent:', info.response);
    } catch (err) {
      console.error('Error sending email:', err);
    }
  }
  module.exports = sendEmails;


  const cron = require('node-cron');
  const sendEmails = require('./sendEmails');

  cron.schedule('0 9 * * *',async ()=>{
    console.log('⏰ Running daily email job at 9 AM...');
    await sendEmails;
  })