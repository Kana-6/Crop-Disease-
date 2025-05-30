<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GitcoHealth - Rural Healthcare System</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            color: #333;
        }

        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
        }

        .header {
            text-align: center;
            color: white;
            margin-bottom: 30px;
        }

        .header h1 {
            font-size: 3rem;
            margin-bottom: 10px;
            text-shadow: 2px 2px 4px rgba(0,0,0,0.3);
        }

        .header p {
            font-size: 1.2rem;
            opacity: 0.9;
        }

        .nav-tabs {
            display: flex;
            justify-content: center;
            margin-bottom: 30px;
            gap: 10px;
            flex-wrap: wrap;
        }

        .nav-tab {
            background: rgba(255,255,255,0.2);
            color: white;
            border: none;
            padding: 12px 24px;
            border-radius: 25px;
            cursor: pointer;
            transition: all 0.3s ease;
            backdrop-filter: blur(10px);
        }

        .nav-tab:hover {
            background: rgba(255,255,255,0.3);
            transform: translateY(-2px);
        }

        .nav-tab.active {
            background: white;
            color: #667eea;
            font-weight: bold;
        }

        .page {
            display: none;
            background: white;
            border-radius: 20px;
            padding: 30px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.2);
            backdrop-filter: blur(10px);
        }

        .page.active {
            display: block;
        }

        .profile-section {
            text-align: center;
            margin-bottom: 30px;
            padding: 20px;
            background: linear-gradient(135deg, #f5f7fa 0%, #c3cfe2 100%);
            border-radius: 15px;
        }

        .profile-pic {
            font-size: 4rem;
            margin-bottom: 20px;
        }

        .form-group {
            margin-bottom: 20px;
            text-align: left;
        }

        .form-group label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
            color: #555;
        }

        .form-group input,
        .form-group select,
        .form-group textarea {
            width: 100%;
            padding: 12px;
            border: 2px solid #ddd;
            border-radius: 10px;
            font-size: 16px;
            transition: border-color 0.3s ease;
        }

        .form-group input:focus,
        .form-group select:focus,
        .form-group textarea:focus {
            outline: none;
            border-color: #667eea;
        }

        .btn {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            border: none;
            padding: 12px 30px;
            border-radius: 25px;
            cursor: pointer;
            font-size: 16px;
            font-weight: bold;
            transition: all 0.3s ease;
        }

        .btn:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(0,0,0,0.2);
        }

        .hidden {
            display: none !important;
        }

        .task-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            margin-bottom: 30px;
        }

        .task-card {
            background: linear-gradient(135deg, #f5f7fa 0%, #c3cfe2 100%);
            padding: 25px;
            border-radius: 15px;
            text-align: center;
            cursor: pointer;
            transition: all 0.3s ease;
        }

        .task-card:hover {
            transform: translateY(-5px);
            box-shadow: 0 10px 25px rgba(0,0,0,0.15);
        }

        .task-icon {
            font-size: 3rem;
            margin-bottom: 15px;
        }

        .task-card h3 {
            color: #333;
            margin-bottom: 10px;
        }

        .task-card p {
            color: #666;
            font-size: 14px;
        }

        .about-section {
            background: #f8f9fa;
            padding: 25px;
            border-radius: 15px;
            margin-bottom: 30px;
        }

        .about-section h2 {
            color: #333;
            margin-bottom: 20px;
        }

        .about-section ul {
            list-style: none;
            padding-left: 0;
        }

        .about-section li {
            padding: 10px 0;
            border-bottom: 1px solid #eee;
            position: relative;
            padding-left: 30px;
        }

        .about-section li:before {
            content: "✓";
            color: #28a745;
            font-weight: bold;
            position: absolute;
            left: 0;
        }

        .team-section {
            margin-top: 30px;
        }

        .team-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
            gap: 20px;
            margin-top: 20px;
        }

        .team-member {
            text-align: center;
            padding: 20px;
            background: #f8f9fa;
            border-radius: 15px;
        }

        .team-icon {
            font-size: 3rem;
            margin-bottom: 15px;
        }

        .symptoms-form {
            background: #f8f9fa;
            padding: 25px;
            border-radius: 15px;
            margin-bottom: 30px;
        }

        .chatbot-container {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            border-radius: 15px;
            padding: 20px;
            margin-bottom: 30px;
            color: white;
        }

        .chatbot-header {
            display: flex;
            align-items: center;
            margin-bottom: 20px;
            gap: 15px;
        }

        .chatbot-icon {
            font-size: 2.5rem;
            animation: pulse 2s infinite;
        }

        @keyframes pulse {
            0% { transform: scale(1); }
            50% { transform: scale(1.1); }
            100% { transform: scale(1); }
        }

        .chatbot-messages {
            max-height: 300px;
            overflow-y: auto;
            background: rgba(255,255,255,0.1);
            border-radius: 10px;
            padding: 15px;
            margin-bottom: 15px;
            backdrop-filter: blur(10px);
        }

        .message {
            margin-bottom: 15px;
            padding: 10px 15px;
            border-radius: 15px;
            max-width: 80%;
        }

        .message.bot {
            background: rgba(255,255,255,0.2);
            align-self: flex-start;
        }

        .message.user {
            background: rgba(255,255,255,0.3);
            align-self: flex-end;
            margin-left: auto;
            text-align: right;
        }

        .chat-input-container {
            display: flex;
            gap: 10px;
        }

        .chat-input {
            flex: 1;
            padding: 12px;
            border: none;
            border-radius: 25px;
            background: rgba(255,255,255,0.2);
            color: white;
            backdrop-filter: blur(10px);
        }

        .chat-input::placeholder {
            color: rgba(255,255,255,0.7);
        }

        .chat-send-btn {
            background: rgba(255,255,255,0.3);
            border: none;
            border-radius: 50%;
            width: 45px;
            height: 45px;
            color: white;
            cursor: pointer;
            display: flex;
            align-items: center;
            justify-content: center;
            transition: all 0.3s ease;
        }

        .chat-send-btn:hover {
            background: rgba(255,255,255,0.4);
            transform: scale(1.1);
        }

        .result-card {
            background: #f8f9fa;
            padding: 20px;
            border-radius: 15px;
            margin-bottom: 15px;
            border-left: 4px solid #28a745;
        }

        .result-card.risk-high {
            border-left-color: #dc3545;
            background: #fff5f5;
        }

        .result-card.risk-moderate {
            border-left-color: #ffc107;
            background: #fffbf0;
        }

        .result-card.risk-low {
            border-left-color: #28a745;
            background: #f0fff4;
        }

        .news-grid {
            display: grid;
            gap: 20px;
        }

        .news-item {
            background: #f8f9fa;
            padding: 25px;
            border-radius: 15px;
            transition: all 0.3s ease;
        }

        .news-item:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(0,0,0,0.1);
        }

        .news-date {
            color: #666;
            font-size: 14px;
            margin-bottom: 10px;
        }

        .calendar {
            background: #f8f9fa;
            padding: 25px;
            border-radius: 15px;
            margin-bottom: 30px;
        }

        .calendar-header {
            display: flex;
            justify-content: center;
            gap: 20px;
            margin-bottom: 20px;
        }

        .calendar-header select {
            padding: 10px;
            border-radius: 10px;
            border: 2px solid #ddd;
        }

        .vaccination-list {
            margin-top: 30px;
        }

        @media (max-width: 768px) {
            .container {
                padding: 10px;
            }
            
            .header h1 {
                font-size: 2rem;
            }
            
            .nav-tabs {
                flex-direction: column;
                align-items: center;
            }
            
            .page {
                padding: 20px;
            }
            
            .chatbot-header {
                flex-direction: column;
                text-align: center;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <h1>🌿 GitcoHealth</h1>
            <p>Connecting Rural Communities to Quality Healthcare</p>
        </header>
        <nav class="nav-tabs">
            <button class="nav-tab active" onclick="showPage('home')">Home</button>
            <button class="nav-tab" onclick="showPage('symptoms')">Enter Symptoms</button>
            <button class="nav-tab" onclick="showPage('news')">Latest News</button>
            <button class="nav-tab" onclick="showPage('reminders')">Reminders</button>
        </nav>
        <main>
            <div id="home" class="page active">
                <div class="profile-section" id="profile-section">
                  <div class="profile-pic" id="profile-pic">👤</div>
                  <div id="profile-form-section">
                    <form id="profile-form" onsubmit="event.preventDefault(); setProfile();">
                      <div class="form-group">
                        <label for="profile-name">Name:</label>
                        <input type="text" id="profile-name" placeholder="Enter your name" required>
                      </div>
                      <div class="form-group">
                        <label for="profile-age">Age:</label>
                        <input type="number" id="profile-age" placeholder="Enter your age" required>
                      </div>
                      <div class="form-group">
                        <label for="profile-gender">Gender:</label>
                        <select id="profile-gender" required>
                          <option value="">Select Gender</option>
                          <option value="male">Male</option>
                          <option value="female">Female</option>
                          <option value="other">Other</option>
                        </select>
                      </div>
                      <button class="btn" type="submit">Enter</button>
                    </form>
                  </div>
                  <div id="profile-display-section" class="hidden">
                    <h2 id="profile-welcome"></h2>
                    <p id="profile-details"></p>
                  </div>
                </div>
                <div class="task-grid">
                    <div class="task-card" onclick="showPage('symptoms')">
                        <div class="task-icon">🩺</div>
                        <h3>Enter Your Symptoms</h3>
                        <p>Get instant health assessment and recommendations</p>
                    </div>
                    <div class="task-card" onclick="showPage('news')">
                        <div class="task-icon">📰</div>
                        <h3>Latest News</h3>
                        <p>Stay updated with medical news and health tips</p>
                    </div>
                    <div class="task-card" onclick="showPage('reminders')">
                        <div class="task-icon">📅</div>
                        <h3>Reminders</h3>
                        <p>Track vaccination dates and appointments</p>
                    </div>
                </div>
                <div class="about-section">
                    <h2>About Our System</h2>
                    <ul>
                        <li>AI-powered symptom analysis and health recommendations</li>
                        <li>Latest medical news and health awareness information</li>
                        <li>Vaccination tracking and health reminders</li>
                        <li>Easy-to-use interface designed for rural communities</li>
                        <li>Multilingual support for better accessibility</li>
                    </ul>
                </div>
                <div class="team-section">
                    <h2>Our Team</h2>
                    <div class="team-grid" id="team-grid"></div>
                </div>
            </div>
            <div id="symptoms" class="page">
                <h2>🩺 Symptom Checker</h2>
                
                <!-- Chatbot Section -->
                <div class="chatbot-container">
                    <div class="chatbot-header">
                        <div class="chatbot-icon">🤖</div>
                        <div>
                            <h3>AI Health Assistant</h3>
                            <p>Ask me about your symptoms and get instant guidance</p>
                        </div>
                    </div>
                    <div class="chatbot-messages" id="chatbot-messages">
                        <div class="message bot">
                            <strong>🤖 Health Assistant:</strong> Hello! I'm here to help you understand your symptoms. Please describe how you're feeling, and I'll provide some guidance. Remember, I'm not a replacement for professional medical advice.
                        </div>
                    </div>
                    <div class="chat-input-container">
                        <input type="text" class="chat-input" id="chat-input" placeholder="Describe your symptoms..." onkeypress="handleChatKeyPress(event)">
                        <button class="chat-send-btn" onclick="sendChatMessage()">
                            <span>📨</span>
                        </button>
                    </div>
                </div>

                <!-- Original Form -->
                <form class="symptoms-form" onsubmit="event.preventDefault();analyzeSymptoms();">
                    <h3>📋 Detailed Symptom Analysis</h3>
                    <div class="form-group">
                        <label for="age">Age:</label>
                        <input type="number" id="age" placeholder="Enter your age">
                    </div>
                    <div class="form-group">
                        <label for="gender">Gender:</label>
                        <select id="gender">
                            <option value="">Select Gender</option>
                            <option value="male">Male</option>
                            <option value="female">Female</option>
                            <option value="other">Other</option>
                        </select>
                    </div>
                    <div class="form-group">
                        <label for="symptoms">Describe your symptoms:</label>
                        <textarea id="symptoms" rows="4" placeholder="Please describe your symptoms in detail..."></textarea>
                    </div>
                    <div class="form-group">
                        <label for="duration">How long have you had these symptoms?</label>
                        <select id="duration">
                            <option value="">Select Duration</option>
                            <option value="less-than-day">Less than a day</option>
                            <option value="1-3-days">1-3 days</option>
                            <option value="4-7-days">4-7 days</option>
                            <option value="more-than-week">More than a week</option>
                            <option value="chronic">Chronic (ongoing)</option>
                        </select>
                    </div>
                    <button class="btn" type="submit">Analyze Symptoms</button>
                </form>
                <div id="results" class="hidden">
                    <h3>Analysis Results</h3>
                    <div id="result-content"></div>
                </div>
            </div>
            <div id="news" class="page">
                <h2>📰 Latest Medical News</h2>
                <div class="news-grid">
                    <div class="news-item">
                        <h3>New Vaccination Drive Launched in Rural Areas</h3>
                        <p class="news-date">May 25, 2025</p>
                        <p>The government has announced a comprehensive vaccination drive targeting rural communities to improve healthcare coverage and prevent seasonal diseases.</p>
                    </div>
                    <div class="news-item">
                        <h3>Telemedicine Services Expanding to Remote Villages</h3>
                        <p class="news-date">May 22, 2025</p>
                        <p>Digital healthcare platforms are now reaching remote villages, providing access to specialist consultations and medical advice through mobile networks.</p>
                    </div>
                    <div class="news-item">
                        <h3>Monsoon Health Advisory: Prevention Tips</h3>
                        <p class="news-date">May 20, 2025</p>
                        <p>Health experts share essential tips to prevent monsoon-related diseases like malaria, dengue, and water-borne infections in rural communities.</p>
                    </div>
                    <div class="news-item">
                        <h3>Mobile Health Units Serve 50,000+ Rural Patients</h3>
                        <p class="news-date">May 18, 2025</p>
                        <p>State mobile health units have successfully provided medical services to over 50,000 patients in remote areas, significantly improving healthcare accessibility.</p>
                    </div>
                    <div class="news-item">
                        <h3>Traditional Medicine Integration in Rural Healthcare</h3>
                        <p class="news-date">May 15, 2025</p>
                        <p>New initiative combines traditional healing practices with modern medicine to provide culturally appropriate healthcare solutions for rural populations.</p>
                    </div>
                </div>
            </div>
            <div id="reminders" class="page">
                <h2>📅 Health Reminders & Vaccination Calendar</h2>
                <div class="calendar">
                    <div class="calendar-header">
                        <select id="calendar-month"></select>
                        <select id="calendar-year"></select>
                    </div>
                    <div class="calendar-grid" id="calendar-grid"></div>
                </div>
                <div class="vaccination-list">
                    <h3>📋 Upcoming Vaccinations</h3>
                    <div>
                        <div class="result-card">
                            <h4>🩹 June 5, 2025 - Hepatitis B Booster</h4>
                            <p>Second dose of Hepatitis B vaccination for adults. Visit the local health center between 9 AM - 4 PM.</p>
                        </div>
                        <div class="result-card">
                            <h4>🩹 June 12, 2025 - Seasonal Flu Vaccine</h4>
                            <p>Annual influenza vaccination recommended for all age groups. Mobile health unit will be available.</p>
                        </div>
                        <div class="result-card">
                            <h4>🩹 June 20, 2025 - Tetanus Shot</h4>
                            <p>Tetanus booster vaccination (every 10 years). Especially important for farmers and manual workers.</p>
                        </div>
                        <div class="result-card">
                            <h4>🩹 June 28, 2025 - COVID-19 Booster</h4>
                            <p>Updated COVID-19 booster dose. Free vaccination camp at the community center.</p>
                        </div>
                    </div>
                </div>
                <div class="about-section">
                    <h3>⚡ Health Reminders</h3>
                    <div>
                        <div class="result-card risk-low">
                            <h4>💊 Daily Medication Reminder</h4>
                            <p>Don't forget to take your prescribed medications. Set daily alarms for consistent treatment.</p>
                        </div>
                        <div class="result-card risk-moderate">
                            <h4>🏃‍♂ Weekly Health Check</h4>
                            <p>Monitor your blood pressure and weight weekly. Record in your health diary.</p>
                        </div>
                        <div class="result-card risk-low">
                            <h4>🦷 Dental Care Reminder</h4>
                            <p>Schedule your bi-annual dental check-up. Next appointment due: August 2025.</p>
                        </div>
                    </div>
                </div>
            </div>
        </main>
    </div>

    <script>
        // Global variables
        let userProfile = {};
        
        // Chatbot Knowledge Base
        const symptomResponses = {
            fever: {
                keywords: ['fever', 'temperature', 'hot', 'burning', 'chills'],
                response: "🌡️ **Fever Assessment:** A fever usually indicates your body is fighting an infection. For adults, temperatures above 100.4°F (38°C) are considered fever.\n\n**Immediate care:**\n• Stay hydrated with water, clear broths\n• Rest and avoid strenuous activity\n• Use fever reducers like paracetamol if needed\n• Cool compress on forehead\n\n**⚠️ Seek medical attention if:**\n• Fever above 103°F (39.4°C)\n• Lasts more than 3 days\n• Accompanied by severe headache, stiff neck, or difficulty breathing"
            },
            headache: {
                keywords: ['headache', 'head pain', 'migraine', 'head ache'],
                response: "🧠 **Headache Analysis:** Headaches can have various causes from tension to dehydration.\n\n**Common remedies:**\n• Rest in a quiet, dark room\n• Apply cold or warm compress\n• Stay hydrated\n• Gentle neck and shoulder massage\n• Over-the-counter pain relief\n\n**⚠️ Seek immediate medical help if:**\n• Sudden, severe headache unlike any before\n• Headache with fever, stiff neck, confusion\n• Headache after head injury\n• Progressive worsening over days"
            },
            cough: {
                keywords: ['cough', 'coughing', 'throat', 'chest'],
                response: "🫁 **Cough Evaluation:** Coughs can be dry or productive and have various causes.\n\n**Home remedies:**\n• Honey and warm water\n• Steam inhalation\n• Stay hydrated\n• Elevate head while sleeping\n• Avoid irritants like smoke\n\n**Types of concern:**\n• Persistent cough (>3 weeks)\n• Blood in cough\n• High fever with cough\n• Difficulty breathing\n\n**💡 Tip:** Wet coughs help clear mucus, don't suppress them completely"
            },
            stomach: {
                keywords: ['stomach', 'nausea', 'vomiting', 'diarrhea', 'abdominal', 'belly', 'tummy'],
                response: "🤢 **Digestive Issues:** Stomach problems can range from mild indigestion to serious conditions.\n\n**Initial care:**\n• Clear liquids (water, clear broths)\n• BRAT diet (Bananas, Rice, Applesauce, Toast)\n• Avoid dairy, fatty, spicy foods\n• Small, frequent meals\n• Ginger tea for nausea\n\n**⚠️ Seek medical care for:**\n• Severe abdominal pain\n• Blood in vomit or stool\n• Signs of dehydration\n• High fever with stomach symptoms\n• Symptoms lasting >2 days"
            },
            breathing: {
                keywords: ['breathing', 'shortness of breath', 'wheezing', 'chest tight'],
                response: "🫁 **Breathing Difficulties:** This can be serious and requires careful assessment.\n\n**Immediate steps:**\n• Sit upright, lean slightly forward\n• Loosen tight clothing\n• Try slow, deep breathing\n• Stay calm\n• Ensure good ventilation\n\n**🚨 SEEK IMMEDIATE MEDICAL HELP:**\n• Severe difficulty breathing\n• Chest pain with breathing problems\n• Blue lips or fingernails\n• Cannot speak in full sentences\n• Wheezing or gasping\n\n**This is a potentially serious symptom that often requires professional evaluation.**"
            }
        };

        // Chatbot Functions
        function handleChatKeyPress(event) {
            if (event.key === 'Enter') {
                sendChatMessage();
            }
        }

        function sendChatMessage() {
            const input = document.getElementById('chat-input');
            const message = input.value.trim();
            
            if (!message) return;
            
            // Add user message
            addChatMessage(message, 'user');
            input.value = '';
            
            // Generate bot response
            setTimeout(() => {
                const response = generateBotResponse(message);
                addChatMessage(response, 'bot');
            }, 1000);
        }

        function addChatMessage(message, sender) {
            const messagesContainer = document.getElementById('chatbot-messages');
            const messageDiv = document.createElement('div');
            messageDiv.className = `message ${sender}`;
            
            if (sender === 'bot') {
                messageDiv.innerHTML = `<strong>🤖 Health Assistant:</strong> ${message.replace(/\n/g, '<br>')}`;
            } else {
                messageDiv.innerHTML = `<strong>You:</strong> ${message}`;
            }
            
            messagesContainer.appendChild(messageDiv);
            messagesContainer.scrollTop = messagesContainer.scrollHeight;
        }

        function generateBotResponse(userMessage) {
            const lowerMessage = userMessage.toLowerCase();
            
            // Check for emergency keywords
            const emergencyKeywords = ['emergency', 'urgent', 'severe', 'can\'t breathe', 'chest pain', 'heart attack', 'stroke'];
            if (emergencyKeywords.some(keyword => lowerMessage.includes(keyword))) {
                return "🚨 **EMERGENCY ALERT:** If this is a medical emergency, please contact emergency services immediately!\n\n📞 **Emergency Numbers:**\n• Call 108 (India Emergency)\n• Go to nearest hospital\n• Contact local health center\n\nFor non-emergency symptoms, I'm here to help guide you.";
            }
            
            // Check symptom categories
            for (const [category, data] of Object.entries(symptomResponses)) {
                if (data.keywords.some(keyword => lowerMessage.includes(keyword))) {
                    return data.response;
                }
            }
            
            // General health queries
            if (lowerMessage.includes('pain') && !lowerMessage.includes('head')) {
                return "🩹 **General Pain Management:**\n\n**For mild to moderate pain:**\n• Rest the affected area\n• Apply ice for acute injuries (first 24-48 hours)\n• Apply heat for muscle tension\n• Over-the-counter pain relievers\n• Gentle stretching if appropriate\n\n**⚠️ See a doctor if:**\n• Severe or worsening pain\n• Pain after injury\n• Pain with swelling, redness, warmth\n• Pain interfering with daily activities";
            }
            
            if (lowerMessage.includes('tired') || lowerMessage.includes('fatigue') || lowerMessage.includes('weakness')) {
                return "😴 **Fatigue and Weakness:**\n\n**Common causes:**\n• Lack of sleep\n• Dehydration\n• Poor nutrition\n• Stress\n• Underlying medical conditions\n\n**Self-care steps:**\n• Ensure 7-9 hours of sleep\n• Stay hydrated\n• Eat balanced meals\n• Manage stress\n• Light exercise\n\n**Consult a doctor if fatigue is:**\n• Persistent (>2 weeks)\n• Severe and sudden\n• Accompanied by other symptoms";
            }
            
            // General wellness advice
            if (lowerMessage.includes('healthy') || lowerMessage.includes('prevention')) {
                return "🌟 **General Health Tips:**\n\n**Daily habits for good health:**\n• Drink plenty of water (8-10 glasses/day)\n• Eat fruits and vegetables daily\n• Get regular exercise (30 min/day)\n• Sleep 7-9 hours nightly\n• Wash hands frequently\n• Avoid smoking and excessive alcohol\n• Manage stress through relaxation\n• Regular health check-ups\n\n**💡 Remember:** Prevention is always better than cure!";
            }
            
            // Default responses for unrecognized input
            const defaultResponses = [
                "I understand you're concerned about your health. Could you be more specific about your symptoms? For example, are you experiencing pain, fever, nausea, or something else?",
                "I'm here to help! Please describe your symptoms in more detail so I can provide better guidance. What exactly are you feeling?",
                "To give you the most helpful advice, could you tell me more about your specific symptoms? Are you experiencing any pain, discomfort, or other health concerns?",
                "I want to help you with your health concerns. Can you describe your symptoms more specifically? This will help me provide better guidance."
            ];
            
            return defaultResponses[Math.floor(Math.random() * defaultResponses.length)];
        }

        // Profile Functions
        function setProfile() {
            const name = document.getElementById('profile-name').value.trim();
            const age = document.getElementById('profile-age').value.trim();
            const gender = document.getElementById('profile-gender').value;
            
            if (!name || !age || !gender) return;
            
            userProfile = { name, age, gender };
            
            document.getElementById('profile-form-section').classList.add('hidden');
            document.getElementById('profile-display-section').classList.remove('hidden');
            document.getElementById('profile-welcome').textContent = `Welcome, ${name}`;
            document.getElementById('profile-details').textContent = `Age: ${age} | Gender: ${gender.charAt(0).toUpperCase() + gender.slice(1)}`;
            
            // Update profile pic
            const pic = document.getElementById('profile-pic');
            if (gender === 'male') pic.textContent = '👨';
            else if (gender === 'female') pic.textContent = '👩';
            else pic.textContent = '👤';
        }

        // Navigation Functions
        function showPage(pageId) {
            document.querySelectorAll('.page').forEach(page => page.classList.remove('active'));
            document.querySelectorAll('.nav-tab').forEach(tab => tab.classList.remove('active'));
            document.getElementById(pageId).classList.add('active');
            
            const targetTab = Array.from(document.querySelectorAll('.nav-tab')).find(tab => 
                tab.textContent.toLowerCase().includes(pageId));
            if (targetTab) targetTab.classList.add('active');
        }

        // Symptom Analysis Function
        async function analyzeSymptoms() {
            const symptoms = document.getElementById('symptoms').value;
            const age = document.getElementById('age').value;
            const gender = document.getElementById('gender').value;
            const duration = document.getElementById('duration').value;
            
            if (!symptoms.trim()) return alert('Please describe your symptoms');
            
            const resultsDiv = document.getElementById('results');
            const contentDiv = document.getElementById('result-content');
            
            resultsDiv.classList.remove('hidden');
            contentDiv.innerHTML = `<div class="result-card"><em>Analyzing symptoms, please wait...</em></div>`;
            
            // Simulate analysis (replace with actual API call)
            setTimeout(() => {
                const analysis = performSymptomAnalysis(symptoms, age, gender, duration);
                contentDiv.innerHTML = analysis;
                resultsDiv.scrollIntoView({ behavior: 'smooth' });
            }, 2000);
        }

        function performSymptomAnalysis(symptoms, age, gender, duration) {
            const lowerSymptoms = symptoms.toLowerCase();
            
            // Emergency symptoms
            const emergencySymptoms = ['chest pain', 'difficulty breathing', 'severe headache', 'stroke', 'heart attack'];
            if (emergencySymptoms.some(symptom => lowerSymptoms.includes(symptom))) {
                return `<div class="result-card risk-high">
                    <h4>🚨 URGENT MEDICAL ATTENTION REQUIRED</h4>
                    <p>Based on your symptoms, you should seek immediate medical attention. Please contact emergency services or visit the nearest hospital immediately.</p>
                    <p><strong>Emergency Contact:</strong> 108 (India)</p>
                </div>`;
            }
            
            // Common symptoms analysis
            let riskLevel = 'low';
            let recommendations = [];
            let possibleConditions = [];
            
            if (lowerSymptoms.includes('fever')) {
                riskLevel = 'moderate';
                possibleConditions.push('Viral or bacterial infection');
                recommendations.push('Monitor temperature regularly');
                recommendations.push('Stay hydrated and rest');
            }
            
            if (lowerSymptoms.includes('cough')) {
                possibleConditions.push('Respiratory infection or irritation');
                recommendations.push('Use honey and warm water for throat soothing');
                recommendations.push('Avoid smoking and pollutants');
            }
            
            if (lowerSymptoms.includes('headache')) {
                possibleConditions.push('Tension headache or migraine');
                recommendations.push('Rest in a quiet, dark room');
                recommendations.push('Apply cold or warm compress');
            }
            
            if (lowerSymptoms.includes('nausea') || lowerSymptoms.includes('vomiting')) {
                possibleConditions.push('Gastroenteritis or food poisoning');
                recommendations.push('Stay hydrated with clear fluids');
                recommendations.push('Follow BRAT diet (Bananas, Rice, Applesauce, Toast)');
            }
            
            // Duration-based assessment
            if (duration === 'more-than-week' || duration === 'chronic') {
                riskLevel = 'moderate';
                recommendations.push('Consider consulting a healthcare provider for persistent symptoms');
            }
            
            // Default recommendations
            if (recommendations.length === 0) {
                recommendations = [
                    'Monitor your symptoms closely',
                    'Stay hydrated and get adequate rest',
                    'Consider over-the-counter remedies if appropriate'
                ];
            }
            
            const riskClass = riskLevel === 'high' ? 'risk-high' : riskLevel === 'moderate' ? 'risk-moderate' : 'risk-low';
            
            return `
                <div class="result-card ${riskClass}">
                    <h4>📋 Symptom Analysis Results</h4>
                    <p><strong>Risk Level:</strong> ${riskLevel.charAt(0).toUpperCase() + riskLevel.slice(1)}</p>
                    ${possibleConditions.length > 0 ? `<p><strong>Possible Conditions:</strong> ${possibleConditions.join(', ')}</p>` : ''}
                    <p><strong>Recommendations:</strong></p>
                    <ul>
                        ${recommendations.map(rec => `<li>${rec}</li>`).join('')}
                    </ul>
                    <p><em>⚠️ Disclaimer: This is not a medical diagnosis. Please consult a healthcare professional for proper medical advice.</em></p>
                </div>
            `;
        }

        // Initialize team members
        function initializeTeam() {
            const teamMembers = [
                { icon: '👨‍⚕️', name: 'Dr. Rajesh Kumar', role: 'Chief Medical Officer' },
                { icon: '👩‍⚕️', name: 'Dr. Priya Sharma', role: 'Rural Health Specialist' },
                { icon: '👨‍💻', name: 'Amit Patel', role: 'Technology Lead' },
                { icon: '👩‍💼', name: 'Sunita Singh', role: 'Community Outreach' }
            ];
            
            const teamGrid = document.getElementById('team-grid');
            teamMembers.forEach(member => {
                const memberDiv = document.createElement('div');
                memberDiv.className = 'team-member';
                memberDiv.innerHTML = `
                    <div class="team-icon">${member.icon}</div>
                    <h4 class="team-name">${member.name}</h4>
                    <p class="team-role">${member.role}</p>
                `;
                teamGrid.appendChild(memberDiv);
            });
        }

        // Initialize calendar
        function initializeCalendar() {
            const monthSelect = document.getElementById('calendar-month');
            const yearSelect = document.getElementById('calendar-year');
            
            const months = [
                'January', 'February', 'March', 'April', 'May', 'June',
                'July', 'August', 'September', 'October', 'November', 'December'
            ];
            
            months.forEach((month, index) => {
                const option = document.createElement('option');
                option.value = index;
                option.textContent = month;
                if (index === 5) option.selected = true; // June
                monthSelect.appendChild(option);
            });
            
            for (let year = 2024; year <= 2030; year++) {
                const option = document.createElement('option');
                option.value = year;
                option.textContent = year;
                if (year === 2025) option.selected = true;
                yearSelect.appendChild(option);
            }
        }

        // Initialize app
        document.addEventListener('DOMContentLoaded', function() {
            initializeTeam();
            initializeCalendar();
            
            // Add welcome message to chatbot
            setTimeout(() => {
                addChatMessage("Welcome to GitcoHealth! I'm your AI Health Assistant. How are you feeling today? Please describe any symptoms you're experiencing.", 'bot');
            }, 1000);
        });
    </script>
</body>
</html>
    <div class="container">
        <header class="header">
            <div class="language-switch" onclick="toggleLanguage()">
                <span class="language-icon">🌐</span>
                <span class="language-text" data-en="English" data-hi="हिंदी" data-kn="ಕನ್ನಡ">English</span>
            </div>
            <h1>🌿 <span data-en="ArogyaVriksh" data-hi="आरोग्यवृक्ष" data-kn="ಆರೋಗ್ಯವೃಕ್ಷ">ArogyaVriksh</span></h1>
            <p><span data-en="Connecting Rural Communities to Quality Healthcare" data-hi="ग्रामीण समुदायों को गुणवत्तापूर्ण स्वास्थ्य सेवाओं से जोड़ना" data-kn="ಗ್ರಾಮೀಣ ಸಮುದಾಯಗಳನ್ನು ಗುಣಮಟ್ಟದ ಆರೋಗ್ಯ ಸೇವೆಗಳಿಗೆ ಸಂಪರ್ಕಿಸುವುದು">Connecting Rural Communities to Quality Healthcare</span></p>
        </header>
        <nav class="nav-tabs">
            <button class="nav-tab active" onclick="showPage('home')"><span data-en="Home" data-hi="होम" data-kn="ಮುಖಪುಟ">Home</span></button>
            <button class="nav-tab" onclick="showPage('symptoms')"><span data-en="Enter Symptoms" data-hi="लक्षण दर्ज करें" data-kn="ಲಕ್ಷಣಗಳನ್ನು ನಮೂದಿಸಿ">Enter Symptoms</span></button>
            <button class="nav-tab" onclick="showPage('news')"><span data-en="Latest News" data-hi="ताज़ा खबर" data-kn="ಇತ್ತೀಚಿನ ಸುದ್ದಿ">Latest News</span></button>
            <button class="nav-tab" onclick="showPage('reminders')"><span data-en="Reminders" data-hi="रिमाइंडर" data-kn="ಜ್ಞಾಪನೆಗಳು">Reminders</span></button>
        </nav>
        <!-- HOME PAGE -->
        <div id="home" class="page active">
            <div class="profile-section">
                <div class="profile-pic">👤</div>
                <h2><span data-en="Welcome, User" data-hi="स्वागत है, उपयोगकर्ता" data-kn="ಸ್ವಾಗತ, ಬಳಕೆದಾರ">Welcome, User</span></h2>
                <p><span data-en="Your Rural Healthcare Companion" data-hi="आपका ग्रामीण स्वास्थ्य सहायक" data-kn="ನಿಮ್ಮ ಗ್ರಾಮೀಣ ಆರೋಗ್ಯ ಸಹಚರ">Your Rural Healthcare Companion</span></p>
            </div>
            <div class="task-grid">
                <div class="task-card" onclick="showPage('symptoms')">
                    <div class="task-icon">🩺</div>
                    <h3><span data-en="Enter Your Symptoms" data-hi="अपने लक्षण दर्ज करें" data-kn="ನಿಮ್ಮ ಲಕ್ಷಣಗಳನ್ನು ನಮೂದಿಸಿ">Enter Your Symptoms</span></h3>
                    <p><span data-en="Get instant health assessment and recommendations" data-hi="तुरंत स्वास्थ्य मूल्यांकन और सिफारिशें प्राप्त करें" data-kn="ತಕ್ಷಣದ ಆರೋಗ್ಯ ಮೌಲ್ಯಮಾಪನ ಮತ್ತು ಶಿಫಾರಸುಗಳನ್ನು ಪಡೆಯಿರಿ">Get instant health assessment and recommendations</span></p>
                </div>
                <div class="task-card" onclick="showPage('news')">
                    <div class="task-icon">📰</div>
                    <h3><span data-en="Latest News" data-hi="ताज़ा खबर" data-kn="ಇತ್ತೀಚಿನ ಸುದ್ದಿ">Latest News</span></h3>
                    <p><span data-en="Stay updated with medical news and health tips" data-hi="चिकित्सा समाचार और स्वास्थ्य सुझावों के साथ अपडेट रहें" data-kn="ವೈದ್ಯಕೀಯ ಸುದ್ದಿ ಮತ್ತು ಆರೋಗ್ಯ ಸಲಹೆಗಳನ್ನು ಪಡೆಯಿರಿ">Stay updated with medical news and health tips</span></p>
                </div>
                <div class="task-card" onclick="showPage('reminders')">
                    <div class="task-icon">📅</div>
                    <h3><span data-en="Reminders" data-hi="रिमाइंडर" data-kn="ಜ್ಞಾಪನೆಗಳು">Reminders</span></h3>
                    <p><span data-en="Track vaccination dates and appointments" data-hi="टीकाकरण की तारीखें और अपॉइंटमेंट ट्रैक करें" data-kn="ಟೀಕಾಕರಣ ದಿನಾಂಕಗಳು ಮತ್ತು ನೇಮಕಾತಿಗಳನ್ನು ಟ್ರ್ಯಾಕ್ ಮಾಡಿ">Track vaccination dates and appointments</span></p>
                </div>
            </div>
            <div class="about-section">
                <h2><span data-en="About Our System" data-hi="हमारे सिस्टम के बारे में" data-kn="ನಮ್ಮ ವ್ಯವಸ್ಥೆಯ ಬಗ್ಗೆ">About Our System</span></h2>
                <p><span data-en="Our Rural Healthcare Management System is designed to bridge the gap between rural communities and quality healthcare services. We provide:" data-hi="हमारी ग्रामीण स्वास्थ्य प्रबंधन प्रणाली ग्रामीण समुदायों और गुणवत्तापूर्ण स्वास्थ्य सेवाओं के बीच की खाई को पाटने के लिए डिज़ाइन की गई है। हम प्रदान करते हैं:" data-kn="ನಮ್ಮ ಗ್ರಾಮೀಣ ಆರೋಗ್ಯ ನಿರ್ವಹಣಾ ವ್ಯವಸ್ಥೆ ಗ್ರಾಮೀಣ ಸಮುದಾಯಗಳು ಮತ್ತು ಗುಣಮಟ್ಟದ ಆರೋಗ್ಯ ಸೇವೆಗಳ ಮಧ್ಯೆ ಇರುವ ಅಂತರವನ್ನು ಕಡಿಮೆ ಮಾಡಲು ವಿನ್ಯಾಸಗೊಳಿಸಲಾಗಿದೆ. ನಾವು ನೀಡುತ್ತೇವೆ:">Our Rural Healthcare Management System is designed to bridge the gap between rural communities and quality healthcare services. We provide:</span></p>
                <ul style="margin-top: 1rem; margin-left: 2rem;">
                    <li><span data-en="AI-powered symptom analysis and health recommendations" data-hi="एआई-संचालित लक्षण विश्लेषण और स्वास्थ्य सिफारिशें" data-kn="ಎಐ ಆಧಾರಿತ ಲಕ್ಷಣ ವಿಶ್ಲೇಷಣೆ ಮತ್ತು ಆರೋಗ್ಯ ಶಿಫಾರಸುಗಳು">AI-powered symptom analysis and health recommendations</span></li>
                    <li><span data-en="Latest medical news and health awareness information" data-hi="नवीनतम चिकित्सा समाचार और स्वास्थ्य जागरूकता जानकारी" data-kn="ಇತ್ತೀಚಿನ ವೈದ್ಯಕೀಯ ಸುದ್ದಿ ಮತ್ತು ಆರೋಗ್ಯ ಜಾಗೃತಿ ಮಾಹಿತಿ">Latest medical news and health awareness information</span></li>
                    <li><span data-en="Vaccination tracking and health reminders" data-hi="टीकाकरण ट्रैकिंग और स्वास्थ्य रिमाइंडर" data-kn="ಟೀಕಾಕರಣ ಟ್ರ್ಯಾಕಿಂಗ್ ಮತ್ತು ಆರೋಗ್ಯ ಜ್ಞಾಪನೆಗಳು">Vaccination tracking and health reminders</span></li>
                    <li><span data-en="Easy-to-use interface designed for rural communities" data-hi="ग्रामीण समुदायों के लिए डिज़ाइन किया गया उपयोग में आसान इंटरफेस" data-kn="ಗ್ರಾಮೀಣ ಸಮುದಾಯಗಳಿಗಾಗಿ ವಿನ್ಯಾಸಗೊಳಿಸಿದ ಸುಲಭ ಬಳಕೆದಾರ ಇಂಟರ್ಫೇಸ್">Easy-to-use interface designed for rural communities</span></li>
                    <li><span data-en="Multilingual support for better accessibility" data-hi="बेहतर पहुंच के लिए बहुभाषी समर्थन" data-kn="ಉತ್ತಮ ಪ್ರವೇಶಕ್ಕಾಗಿ ಬಹುಭಾಷಾ ಬೆಂಬಲ">Multilingual support for better accessibility</span></li>
                </ul>
            </div>
            <div class="team-section">
                <h2><span data-en="Our Team" data-hi="हमारी टीम" data-kn="ನಮ್ಮ ತಂಡ">Our Team</span></h2>
                <div class="team-grid">
                    <div class="team-member">
                        <div style="font-size: 2rem; margin-bottom: 0.5rem;">👨‍💻</div>
                        <h4>Ankit Raj</h4>
                        <p><span data-en="Lead Developer" data-hi="लीड डेवलपर" data-kn="ಮುಖ್ಯ ಡೆವಲಪರ್">Lead Developer</span></p>
                    </div>
                    <div class="team-member">
                        <div style="font-size: 2rem; margin-bottom: 0.5rem;">👩‍💻</div>
                        <h4>Reesha Koli</h4>
                        <p><span data-en="Data Scientist" data-hi="डेटा साइंटिस्ट" data-kn="ಡೇಟಾ ಸೈಂಟಿಸ್ಟ್">Data Scientist</span></p>
                    </div>
                    <div class="team-member">
                        <div style="font-size: 2rem; margin-bottom: 0.5rem;">👨‍💻</div>
                        <h4>Sushil C</h4>
                        <p><span data-en="Backend Developer" data-hi="बैकएंड डेवलपर" data-kn="ಬ್ಯಾಕ್ಎಂಡ್ ಡೆವಲಪರ್">Backend Developer</span></p>
                    </div>
                    <div class="team-member">
                        <div style="font-size: 2rem; margin-bottom: 0.5rem;">👩‍💻</div>
                        <h4>Kanishka Naik</h4>
                        <p><span data-en="UI/UX Designer" data-hi="यूआई/यूएक्स डिजाइनर" data-kn="UI/UX ಡಿಸೈನರ್">UI/UX Designer</span></p>
                    </div>
                </div>
            </div>
        </div>
        <!-- SYMPTOMS PAGE -->
        <div id="symptoms" class="page">
            <h2>🩺 <span data-en="Symptom Checker" data-hi="लक्षण जांचकर्ता" data-kn="ಲಕ್ಷಣ ಪರಿಶೀಲಕ">Symptom Checker</span></h2>
            <div class="symptoms-form">
                <div class="form-group">
                    <label for="age"><span data-en="Age:" data-hi="उम्र:" data-kn="ವಯಸ್ಸು:">Age:</span></label>
                    <input type="number" id="age" data-placeholder-en="Enter your age" data-placeholder-hi="अपनी उम्र दर्ज करें" data-placeholder-kn="ನಿಮ್ಮ ವಯಸ್ಸನ್ನು ನಮೂದಿಸಿ" placeholder="Enter your age">
                </div>
                <div class="form-group">
                    <label for="gender"><span data-en="Gender:" data-hi="लिंग:" data-kn="ಲಿಂಗ:">Gender:</span></label>
                    <select id="gender">
                        <option value="" data-en="Select Gender" data-hi="लिंग चुनें" data-kn="ಲಿಂಗ ಆಯ್ಕೆಮಾಡಿ">Select Gender</option>
                        <option value="male" data-en="Male" data-hi="पुरुष" data-kn="ಪುರುಷ">Male</option>
                        <option value="female" data-en="Female" data-hi="महिला" data-kn="ಮಹಿಳೆ">Female</option>
                        <option value="other" data-en="Other" data-hi="अन्य" data-kn="ಇತರೆ">Other</option>
                    </select>
                </div>
                <div class="form-group">
                    <label for="symptoms"><span data-en="Describe your symptoms:" data-hi="अपने लक्षणों का वर्णन करें:" data-kn="ನಿಮ್ಮ ಲಕ್ಷಣಗಳನ್ನು ವಿವರಿಸಿ:">Describe your symptoms:</span></label>
                    <textarea id="symptoms" rows="4" data-placeholder-en="Please describe your symptoms in detail..." data-placeholder-hi="कृपया अपने लक्षणों का विस्तार से वर्णन करें..." data-placeholder-kn="ದಯವಿಟ್ಟು ನಿಮ್ಮ ಲಕ್ಷಣಗಳನ್ನು ವಿವರವಾಗಿ ವಿವರಿಸಿ..." placeholder="Please describe your symptoms in detail..."></textarea>
                </div>
                <div class="form-group">
                    <label for="symptom-images"><span data-en="Add Images (optional):" data-hi="छवियां जोड़ें (वैकल्पिक):" data-kn="ಚಿತ್ರಗಳನ್ನು ಸೇರಿಸಿ (ಐಚ್ಛಿಕ):">Add Images (optional):</span></label>
                    <input type="file" id="symptom-images" accept="image/*" multiple>
                    <div id="image-preview"></div>
                </div>
                <div class="form-group">
                    <label for="duration"><span data-en="How long have you had these symptoms?" data-hi="आपको ये लक्षण कब से हैं?" data-kn="ಈ ಲಕ್ಷಣಗಳು ನಿಮಗೆ ಎಷ್ಟು ಕಾಲವಾಯಿತು?">How long have you had these symptoms?</span></label>
                    <select id="duration">
                        <option value="" data-en="Select Duration" data-hi="अवधि चुनें" data-kn="ಅವಧಿ ಆಯ್ಕೆಮಾಡಿ">Select Duration</option>
                        <option value="less-than-day" data-en="Less than a day" data-hi="एक दिन से कम" data-kn="ಒಂದು ದಿನಕ್ಕಿಂತ ಕಡಿಮೆ">Less than a day</option>
                        <option value="1-3-days" data-en="1-3 days" data-hi="1-3 दिन" data-kn="1-3 ದಿನ">1-3 days</option>
                        <option value="4-7-days" data-en="4-7 days" data-hi="4-7 दिन" data-kn="4-7 ದಿನ">4-7 days</option>
                        <option value="more-than-week" data-en="More than a week" data-hi="एक हफ्ते से अधिक" data-kn="ಒಂದು ವಾರಕ್ಕಿಂತ ಹೆಚ್ಚು">More than a week</option>
                        <option value="chronic" data-en="Chronic (ongoing)" data-hi="क्रोनिक (निरंतर)" data-kn="ದೀರ್ಘಕಾಲದ (ನಿರಂತರ)">Chronic (ongoing)</option>
                    </select>
                </div>
                <button class="btn" onclick="analyzeSymptoms()"><span data-en="Analyze Symptoms" data-hi="लक्षणों का विश्लेषण करें" data-kn="ಲಕ್ಷಣಗಳನ್ನು ವಿಶ್ಲೇಷಿಸಿ">Analyze Symptoms</span></button>
            </div>
            <div id="results" class="hidden">
                <h3><span data-en="Analysis Results" data-hi="विश्लेषण परिणाम" data-kn="ವಿಶ್ಲೇಷಣೆಯ ಫಲಿತಾಂಶಗಳು">Analysis Results</span></h3>
                <div id="result-content"></div>
            </div>
        </div>
        <!-- NEWS PAGE -->
        <div id="news" class="page">
            <h2>📰 <span data-en="Latest Medical News" data-hi="नवीनतम चिकित्सा समाचार" data-kn="ಇತ್ತೀಚಿನ ವೈದ್ಯಕೀಯ ಸುದ್ದಿ">Latest Medical News</span></h2>
            <div class="news-grid">
                <div class="news-item">
                    <h3>
                        <span data-en="New Vaccination Drive Launched in Rural Areas"
                              data-hi="ग्रामीण क्षेत्रों में नया टीकाकरण अभियान शुरू"
                              data-kn="ಗ್ರಾಮೀಣ ಪ್ರದೇಶಗಳಲ್ಲಿ ಹೊಸ ಲಸಿಕೆ ಅಭಿಯಾನ ಆರಂಭ">
                            New Vaccination Drive Launched in Rural Areas
                        </span>
                    </h3>
                    <p class="news-date">May 25, 2025</p>
                    <p>
                        <span data-en="The government has announced a comprehensive vaccination drive targeting rural communities to improve healthcare coverage and prevent seasonal diseases."
                              data-hi="सरकार ने स्वास्थ्य सेवा कवरेज में सुधार और मौसमी बीमारियों को रोकने के लिए ग्रामीण समुदायों को लक्षित करने वाले व्यापक टीकाकरण अभियान की घोषणा की है।"
                              data-kn="ಸರ್ಕಾರವು ಆರೋಗ್ಯ ಸೇವೆ ವ್ಯಾಪ್ತಿಯನ್ನು ಸುಧಾರಿಸಲು ಮತ್ತು ಹಂಗಾಮಿ ರೋಗಗಳನ್ನು ತಡೆಯಲು ಗ್ರಾಮೀಣ ಸಮುದಾಯಗಳನ್ನು ಗುರಿಯಾಗಿಟ್ಟುಕೊಂಡ ಸಮಗ್ರ ಲಸಿಕೆ ಅಭಿಯಾನವನ್ನು ಘೋಷಿಸಿದೆ.">
                            The government has announced a comprehensive vaccination drive targeting rural communities to improve healthcare coverage and prevent seasonal diseases.
                        </span>
                    </p>
                </div>
                <div class="news-item">
                    <h3>
                        <span data-en="Telemedicine Services Expanding to Remote Villages"
                              data-hi="टेलीमेडिसिन सेवाएं दूरस्थ गांवों तक विस्तारित हो रही हैं"
                              data-kn="ಟೆಲಿಮೆಡಿಸಿನ್ ಸೇವೆಗಳು ದೂರದ ಹಳ್ಳಿಗಳಿಗೆ ವಿಸ್ತರಿಸುತ್ತಿವೆ">
                            Telemedicine Services Expanding to Remote Villages
                        </span>
                    </h3>
                    <p class="news-date">May 22, 2025</p>
                    <p>
                        <span data-en="Digital healthcare platforms are now reaching remote villages, providing access to specialist consultations and medical advice through mobile networks."
                              data-hi="डिजिटल स्वास्थ्य सेवा प्लेटफॉर्म अब दूरस्थ गांवों तक पहुंच रहे हैं, जो मोबाइल नेटवर्क के माध्यम से विशेषज्ञ परामर्श और चिकित्सा सलाह तक पहुंच प्रदान कर रहे हैं।"
                              data-kn="ಡಿಜಿಟಲ್ ಆರೋಗ್ಯ ಸೇವಾ ವೇದಿಕೆಗಳು ಈಗ ದೂರದ ಹಳ್ಳಿಗಳಿಗೂ ತಲುಪುತ್ತಿವೆ, ವಿಶೇಷಜ್ಞರ ಸಲಹೆ ಮತ್ತು ವೈದ್ಯಕೀಯ ಸಲಹೆಯನ್ನು ಮೊಬೈಲ್ ನೆಟ್ವರ್ಕ್ ಮೂಲಕ ಒದಗಿಸುತ್ತಿವೆ.">
                            Digital healthcare platforms are now reaching remote villages, providing access to specialist consultations and medical advice through mobile networks.
                        </span>
                    </p>
                </div>
                <div class="news-item">
                    <h3>
                        <span data-en="Monsoon Health Advisory: Prevention Tips"
                              data-hi="मानसून स्वास्थ्य सलाह: रोकथाम के टिप्स"
                              data-kn="ಮಳೆಗಾಲದ ಆರೋಗ್ಯ ಸಲಹೆ: ತಡೆಗಟ್ಟುವ ಸಲಹೆಗಳು">
                            Monsoon Health Advisory: Prevention Tips
                        </span>
                    </h3>
                    <p class="news-date">May 20, 2025</p>
                    <p>
                        <span data-en="Health experts share essential tips to prevent monsoon-related diseases like malaria, dengue, and water-borne infections in rural communities."
                              data-hi="स्वास्थ्य विशेषज्ञ ग्रामीण समुदायों में मलेरिया, डेंगू और जल जनित संक्रमण जैसी मानसून से संबंधित बीमारियों को रोकने के लिए आवश्यक टिप्स साझा करते हैं।"
                              data-kn="ಆರೋಗ್ಯ ಪರಿಣಿತರು ಹಳ್ಳಿಗಳಲ್ಲಿ ಮಲೇರಿಯಾ, ಡೆಂಗ್ಯೂ ಮತ್ತು ನೀರಿನಿಂದ ಹರಡುವ ಇತರ ಕಾಯಿಲೆಗಳನ್ನು ತಡೆಯಲು ಅಗತ್ಯ ಸಲಹೆಗಳನ್ನು ಹಂಚಿಕೊಳ್ಳುತ್ತಾರೆ.">
                            Health experts share essential tips to prevent monsoon-related diseases like malaria, dengue, and water-borne infections in rural communities.
                        </span>
                    </p>
                </div>
                <div class="news-item">
                    <h3>
                        <span data-en="Mobile Health Units Serve 50,000+ Rural Patients"
                              data-hi="मोबाइल स्वास्थ्य इकाइयां 50,000+ ग्रामीण रोगियों की सेवा करती हैं"
                              data-kn="ಮೊಬೈಲ್ ಆರೋಗ್ಯ ಘಟಕಗಳು 50,000+ ಹಳ್ಳಿ ರೋಗಿಗಳಿಗೆ ಸೇವೆ ನೀಡಿವೆ">
                            Mobile Health Units Serve 50,000+ Rural Patients
                        </span>
                    </h3>
                    <p class="news-date">May 18, 2025</p>
                    <p>
                        <span data-en="State mobile health units have successfully provided medical services to over 50,000 patients in remote areas, significantly improving healthcare accessibility."
                              data-hi="राज्य की मोबाइल स्वास्थ्य इकाइयों ने दूरस्थ क्षेत्रों में 50,000 से अधिक रोगियों को चिकित्सा सेवाएं प्रदान की हैं, जिससे स्वास्थ्य देखभाल की पहुंच में काफी सुधार हुआ है।"
                              data-kn="ರಾಜ್ಯದ ಮೊಬೈಲ್ ಆರೋಗ್ಯ ಘಟಕಗಳು ದೂರದ ಪ್ರದೇಶಗಳಲ್ಲಿ 50,000ಕ್ಕೂ ಹೆಚ್ಚು ರೋಗಿಗಳಿಗೆ ವೈದ್ಯಕೀಯ ಸೇವೆಗಳನ್ನು ಯಶಸ್ವಿಯಾಗಿ ಒದಗಿಸಿವೆ, ಇದರಿಂದ ಆರೋಗ್ಯ ಸೇವೆಗಳ ಪ್ರವೇಶತೆಗೆ ಬಹುಮಟ್ಟಿಗೆ ಸಹಾಯವಾಗಿದೆ.">
                            State mobile health units have successfully provided medical services to over 50,000 patients in remote areas, significantly improving healthcare accessibility.
                        </span>
                    </p>
                </div>
                <div class="news-item">
                    <h3>
                        <span data-en="Traditional Medicine Integration in Rural Healthcare"
                              data-hi="ग्रामीण स्वास्थ्य सेवा में पारंपरिक चिकित्सा का एकीकरण"
                              data-kn="ಗ್ರಾಮೀಣ ಆರೋಗ್ಯ ಸೇವೆಯಲ್ಲಿ ಪರಂಪರাগত ವೈದ್ಯಕೀಯ ಸಮನ್ವಯ">
                            Traditional Medicine Integration in Rural Healthcare
                        </span>
                    </h3>
                    <p class="news-date">May 15, 2025</p>
                    <p>
                        <span data-en="New initiative combines traditional healing practices with modern medicine to provide culturally appropriate healthcare solutions for rural populations."
                              data-hi="नई पहल ग्रामीण आबादी के लिए सांस्कृतिक रूप से उपयुक्त स्वास्थ्य देखभाल समाधान प्रदान करने के लिए पारंपरिक उपचार प्रथाओं को आधुनिक चिकित्सा के साथ जोड़ती है।"
                              data-kn="ಹೊಸ ಉಪಕ್ರಮವು ಹಳ್ಳಿಗಳ ಜನರಿಗೆ ಸಂಸ್ಕೃತಿಗೆ ಹೊಂದಿಕೊಂಡ ಆರೋಗ್ಯ ಪರಿಹಾರಗಳನ್ನು ನೀಡಲು ಪರಂಪರೆಯ ಚಿಕಿತ್ಸಾ ವಿಧಾನಗಳನ್ನು ಆಧುನಿಕ ವೈದ್ಯಕೀಯದೊಂದಿಗೆ ಸಂಯೋಜಿಸುತ್ತದೆ.">
                            New initiative combines traditional healing practices with modern medicine to provide culturally appropriate healthcare solutions for rural populations.
                        </span>
                    </p>
                </div>
            </div>
        </div>
        <!-- REMINDERS PAGE -->
        <!-- ... keep your reminders page here as before, just add data-kn attributes for Kannada translations as you did for news ... -->
    </div>
    <script>
        let languages = ['en', 'hi', 'kn'];
        let currentLanguage = 'en';
        function toggleLanguage() {
            currentLanguage = languages[(languages.indexOf(currentLanguage) + 1) % languages.length];
            updateLanguage();
        }
        function updateLanguage() {
            const langSwitchText = document.querySelector('.language-text');
            langSwitchText.textContent = langSwitchText.getAttribute(`data-${currentLanguage}`);
            const translatableElements = document.querySelectorAll('[data-en][data-hi][data-kn]');
            translatableElements.forEach(el => {
                el.textContent = el.getAttribute(`data-${currentLanguage}`);
            });
            const inputsWithPlaceholders = document.querySelectorAll('[data-placeholder-en][data-placeholder-hi][data-placeholder-kn]');
            inputsWithPlaceholders.forEach(input => {
                input.placeholder = input.getAttribute(`data-placeholder-${currentLanguage}`);
            });
            const selectElements = document.querySelectorAll('select');
            selectElements.forEach(select => {
                Array.from(select.options).forEach(option => {
                    if (option.hasAttribute(`data-${currentLanguage}`)) {
                        option.textContent = option.getAttribute(`data-${currentLanguage}`);
                    }
                });
            });
        }
        function showPage(pageId) {
            const pages = document.querySelectorAll('.page');
            pages.forEach(page => page.classList.remove('active'));
            const tabs = document.querySelectorAll('.nav-tab');
            tabs.forEach(tab => tab.classList.remove('active'));
            document.getElementById(pageId).classList.add('active');
            const targetTab = Array.from(tabs).find(tab => {
                const tabTextElements = tab.querySelectorAll('span');
                for (let i = 0; i < tabTextElements.length; i++) {
                    const tabText = tabTextElements[i].textContent.toLowerCase();
                    if (pageId === 'home' && (tabText.includes('home') || tabText.includes('होम') || tabText.includes('ಮುಖಪುಟ'))) return true;
                    if (pageId === 'symptoms' && (tabText.includes('symptoms') || tabText.includes('लक्षण') || tabText.includes('ಲಕ್ಷಣ'))) return true;
                    if (pageId === 'news' && (tabText.includes('news') || tabText.includes('खबर') || tabText.includes('ಸುದ್ದಿ'))) return true;
                    if (pageId === 'reminders' && (tabText.includes('reminders') || tabText.includes('रिमाइंडर') || tabText.includes('ಜ್ಞಾಪನೆ'))) return true;
                }
                return false;
            });
            if (targetTab) targetTab.classList.add('active');
        }
        function analyzeSymptoms() {
            const age = document.getElementById('age').value;
            const gender = document.getElementById('gender').value;
            const symptoms = document.getElementById('symptoms').value;
            const duration = document.getElementById('duration').value;
            const images = document.getElementById('symptom-images').files;
            const alerts = {
                en: 'Please describe your symptoms',
                hi: 'कृपया अपने लक्षणों का वर्णन करें',
                kn: 'ದಯವಿಟ್ಟು ನಿಮ್ಮ ಲಕ್ಷಣಗಳನ್ನು ವಿವರಿಸಿ'
            };
            if (!symptoms.trim()) {
                alert(alerts[currentLanguage]);
                return;
            }
            const results = {
                en: [
                    { risk: 'low', condition: 'Common Cold', description: 'Based on your symptoms, you may have a common cold.', recommendation: 'Home Remedies: Rest, drink warm fluids, honey and ginger tea, steam inhalation. Should resolve in 3-5 days.', prevention: 'Wash hands frequently, avoid close contact with sick people, maintain good hygiene.' }
                ],
                hi: [
                    { risk: 'low', condition: 'सामान्य सर्दी', description: 'आपके लक्षणों के आधार पर, आपको सामान्य सर्दी हो सकती है।', recommendation: 'घरेलू उपचार: आराम करें, गर्म तरल पदार्थ पिएं, शहद और अदरक की चाय, भाप लें। 3-5 दिनों में ठीक हो जाना चाहिए।', prevention: 'बार-बार हाथ धोएं, बीमार लोगों के साथ निकट संपर्क से बचें, अच्छी स्वच्छता बनाए रखें।' }
                ],
                kn: [
                    { risk: 'low', condition: 'ಸಾಮಾನ್ಯ ಶೀತ', description: 'ನಿಮ್ಮ ಲಕ್ಷಣಗಳ ಆಧಾರದ ಮೇಲೆ, ನಿಮಗೆ ಸಾಮಾನ್ಯ ಶೀತ ಇರಬಹುದು.', recommendation: 'ಮನೆ ಚಿಕಿತ್ಸೆ: ವಿಶ್ರಾಂತಿ, ಬಿಸಿ ದ್ರವಗಳನ್ನು ಕುಡಿಯಿರಿ, ಜೇನು ಮತ್ತು ಶುಂಠಿ ಚಹಾ, ಬಾಷ್ಪ ಶ್ವಸನ. 3-5 ದಿನಗಳಲ್ಲಿ ಸುಧಾರಿಸಬಹುದು.', prevention: 'ಹೆಚ್ಚು ಕೈಗಳನ್ನು ತೊಳೆದುಕೊಳ್ಳಿ, ಅಸೌಖ್ಯಿತರೊಂದಿಗೆ ಸಂಪರ್ಕವನ್ನು ತಪ್ಪಿಸಿ, ಉತ್ತಮ ಸ್ವಚ್ಛತೆ ಕಾಯ್ದುಕೊಳ್ಳಿ.' }
                ]
            };
            const resultArray = results[currentLanguage];
            const result = resultArray[Math.floor(Math.random() * resultArray.length)];
            displayResults(result, images);
        }
        function displayResults(result, images) {
            const resultsDiv = document.getElementById('results');
            const contentDiv = document.getElementById('result-content');
            const texts = {
                en: {low: 'LOW RISK', moderate: 'MODERATE RISK', high: 'HIGH RISK', riskLevel: 'Risk Level:', possibleCondition: 'Possible Condition:', analysis: 'Analysis:', recommendation: 'Recommendation:', prevention: 'Prevention:', note: 'Important Note', disclaimer: 'This is an AI-powered preliminary assessment and should not replace professional medical advice. Always consult with a qualified healthcare provider for accurate diagnosis and treatment.', uploadedImages: 'Uploaded Images:'},
                hi: {low: 'कम जोखिम', moderate: 'मध्यम जोखिम', high: 'उच्च जोखिम', riskLevel: 'जोखिम स्तर:', possibleCondition: 'संभावित स्थिति:', analysis: 'विश्लेषण:', recommendation: 'सिफारिश:', prevention: 'रोकथाम:', note: 'महत्वपूर्ण नोट', disclaimer: 'यह एआई-संचालित प्रारंभिक मूल्यांकन है और इसे पेशेवर चिकित्सा सलाह के स्थान पर नहीं लेना चाहिए। सटीक निदान और उपचार के लिए हमेशा योग्य स्वास्थ्य सेवा प्रदाता से परामर्श करें।', uploadedImages: 'अपलोड की गई छवियां:'},
                kn: {low: 'ಕಡಿಮೆ ಅಪಾಯ', moderate: 'ಮಧ್ಯಮ ಅಪಾಯ', high: 'ಹೆಚ್ಚು ಅಪಾಯ', riskLevel: 'ಅಪಾಯ ಮಟ್ಟ:', possibleCondition: 'ಸಾಧ್ಯವಾದ ಸ್ಥಿತಿ:', analysis: 'ವಿಶ್ಲೇಷಣೆ:', recommendation: 'ಶಿಫಾರಸು:', prevention: 'ತಡೆಯುವಿಕೆ:', note: 'ಮುಖ್ಯ ಸೂಚನೆ', disclaimer: 'ಇದು ಎಐ ಆಧಾರಿತ ಪ್ರಾಥಮಿಕ ಮೌಲ್ಯಮಾಪನವಾಗಿದೆ ಮತ್ತು ವೃತ್ತಿಪರ ವೈದ್ಯಕೀಯ ಸಲಹೆಯ ಬದಲು ಬಳಸಬಾರದು. ಖಚಿತ ನಿರ್ಧಾರ ಮತ್ತು ಚಿಕಿತ್ಸೆಗಾಗಿ ಯಾವಾಗಲೂ ಅರ್ಹ ವೈದ್ಯರನ್ನು ಸಂಪರ್ಕಿಸಿ.', uploadedImages: 'ಅಪ್ಲೋಡ್ ಮಾಡಿದ ಚಿತ್ರಗಳು:'}
            };
            let t = texts[currentLanguage];
            let riskClass = '', riskIcon = '', riskText = '';
            switch(result.risk) {
                case 'low': riskClass = 'risk-low'; riskIcon = '🟢'; riskText = t.low; break;
                case 'moderate': riskClass = 'risk-moderate'; riskIcon = '🟡'; riskText = t.moderate; break;
                case 'high': riskClass = 'risk-high'; riskIcon = '🔴'; riskText = t.high; break;
            }
            let imagesHtml = '';
            if(images && images.length) {
                imagesHtml += `<div style="margin-bottom:1rem;"><strong>${t.uploadedImages}</strong><div style="display:flex;gap:1rem;flex-wrap:wrap;">`;
                Array.from(images).forEach(file => {
                    if (file && file.type.startsWith('image/')) {
                        const url = URL.createObjectURL(file);
                        imagesHtml += `<img src="${url}" style="max-width:100px;max-height:100px;border-radius:8px;box-shadow:0 1px 4px rgba(0,0,0,0.12);" alt="uploaded image">`;
                    }
                });
                imagesHtml += '</div></div>';
            }
            contentDiv.innerHTML = `
                ${imagesHtml}
                <div class="result-card ${riskClass}">
                    <h4>${riskIcon} ${t.riskLevel} ${riskText}</h4>
                    <h3>${t.possibleCondition} ${result.condition}</h3>
                    <p><strong>${t.analysis}</strong> ${result.description}</p>
                    <p><strong>${t.recommendation}</strong> ${result.recommendation}</p>
                    <p><strong>${t.prevention}</strong> ${result.prevention}</p>
                </div>
                <div class="result-card">
                    <h4>⚠ ${t.note}</h4>
                    <p>${t.disclaimer}</p>
                </div>
            `;
            resultsDiv.classList.remove('hidden');
            resultsDiv.scrollIntoView({ behavior: 'smooth' });
        }
        document.addEventListener('DOMContentLoaded', function() {
            showPage('home');
            updateLanguage();
            const imageInput = document.getElementById('symptom-images');
            if (imageInput) {
                imageInput.addEventListener('change', function() {
                    const preview = document.getElementById('image-preview');
                    preview.innerHTML = '';
                    Array.from(this.files).forEach(file => {
                        if (file && file.type.startsWith('image/')) {
                            const reader = new FileReader();
                            reader.onload = function(e) {
                                const img = document.createElement('img');
                                img.src = e.target.result;
                                preview.appendChild(img);
                            };
                            reader.readAsDataURL(file);
                        }
                    });
                });
            }
        });
    </script>
</body>
</html>
