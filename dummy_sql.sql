-- ============================================
-- FILM HALL BOOKING SYSTEM - COMPLETE SQL FILE
-- ============================================

-- =========================
-- 1. ADMIN TABLE
-- =========================
CREATE TABLE admin (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    password TEXT NOT NULL
);

-- =========================
-- 2. HALL TABLE
-- =========================
CREATE TABLE hall (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    hall_name TEXT NOT NULL UNIQUE
);

-- =========================
-- 3. MOVIE TABLE (1 movie per hall)
-- =========================
CREATE TABLE movie (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    hall_id INTEGER NOT NULL UNIQUE,
    name TEXT NOT NULL,
    duration INTEGER,
    language TEXT,
    FOREIGN KEY (hall_id) REFERENCES hall(id)
);

-- =========================
-- 4. SEAT TABLE (many seats per hall)
-- =========================
CREATE TABLE seat (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    hall_id INTEGER NOT NULL,
    seat_row TEXT NOT NULL,
    seat_column INTEGER NOT NULL,
    seat_number TEXT NOT NULL,
    FOREIGN KEY (hall_id) REFERENCES hall(id),
    UNIQUE (hall_id, seat_number)
);

-- =========================
-- 5. USER TABLE
-- =========================
CREATE TABLE user (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    age INTEGER
);

-- =========================
-- 6. BOOKING TABLE
-- =========================
CREATE TABLE booking (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    movie_id INTEGER NOT NULL,
    seat_id INTEGER NOT NULL,
    booking_time TEXT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES user(id),
    FOREIGN KEY (movie_id) REFERENCES movie(id),
    FOREIGN KEY (seat_id) REFERENCES seat(id),
    UNIQUE (movie_id, seat_id)
);

-- ============================================
-- 7. INSERT DATA
-- ============================================

-- 7.1 HALLS (IDs 1,2,3)
INSERT INTO hall (id, hall_name) VALUES
(1, 'Hall 1'),
(2, 'Hall 2'),
(3, 'Hall 3');

-- 7.2 MOVIES (1 per hall)
INSERT INTO movie (hall_id, name, duration, language) VALUES
(1, 'Avengers: Endgame', 181, 'English'),
(2, 'Inception', 148, 'English'),
(3, 'Interstellar', 169, 'English');

-- 7.3 SEATS (5 rows x 5 columns for each hall as example)
-- Helper: seat_number = row + column (e.g., A1, A2, B1)
INSERT INTO seat (hall_id, seat_row, seat_column, seat_number) VALUES
-- Hall 1 seats
(1,'A',1,'A1'),(1,'A',2,'A2'),(1,'A',3,'A3'),(1,'A',4,'A4'),(1,'A',5,'A5'),
(1,'B',1,'B1'),(1,'B',2,'B2'),(1,'B',3,'B3'),(1,'B',4,'B4'),(1,'B',5,'B5'),
(1,'C',1,'C1'),(1,'C',2,'C2'),(1,'C',3,'C3'),(1,'C',4,'C4'),(1,'C',5,'C5'),
(1,'D',1,'D1'),(1,'D',2,'D2'),(1,'D',3,'D3'),(1,'D',4,'D4'),(1,'D',5,'D5'),
(1,'E',1,'E1'),(1,'E',2,'E2'),(1,'E',3,'E3'),(1,'E',4,'E4'),(1,'E',5,'E5'),

-- Hall 2 seats
(2,'A',1,'A1'),(2,'A',2,'A2'),(2,'A',3,'A3'),(2,'A',4,'A4'),(2,'A',5,'A5'),
(2,'B',1,'B1'),(2,'B',2,'B2'),(2,'B',3,'B3'),(2,'B',4,'B4'),(2,'B',5,'B5'),
(2,'C',1,'C1'),(2,'C',2,'C2'),(2,'C',3,'C3'),(2,'C',4,'C4'),(2,'C',5,'C5'),
(2,'D',1,'D1'),(2,'D',2,'D2'),(2,'D',3,'D3'),(2,'D',4,'D4'),(2,'D',5,'D5'),
(2,'E',1,'E1'),(2,'E',2,'E2'),(2,'E',3,'E3'),(2,'E',4,'E4'),(2,'E',5,'E5'),

-- Hall 3 seats
(3,'A',1,'A1'),(3,'A',2,'A2'),(3,'A',3,'A3'),(3,'A',4,'A4'),(3,'A',5,'A5'),
(3,'B',1,'B1'),(3,'B',2,'B2'),(3,'B',3,'B3'),(3,'B',4,'B4'),(3,'B',5,'B5'),
(3,'C',1,'C1'),(3,'C',2,'C2'),(3,'C',3,'C3'),(3,'C',4,'C4'),(3,'C',5,'C5'),
(3,'D',1,'D1'),(3,'D',2,'D2'),(3,'D',3,'D3'),(3,'D',4,'D4'),(3,'D',5,'D5'),
(3,'E',1,'E1'),(3,'E',2,'E2'),(3,'E',3,'E3'),(3,'E',4,'E4'),(3,'E',5,'E5');

-- 7.4 USERS
INSERT INTO user (name, age) VALUES
('Hari', 25),
('Anita', 23),
('Ram', 30),
('Shyam', 27);

-- 7.5 SAMPLE BOOKINGS
-- User Hari books seat A1 in Avengers (Hall 1)
INSERT INTO booking (user_id, movie_id, seat_id, booking_time) VALUES
(1, 1, 1, '2026-01-10 12:00:00'),
(2, 2, 26, '2026-01-10 13:00:00'),  -- Anita books A1 in Inception
(3, 3, 51, '2026-01-10 14:00:00');  -- Ram books A1 in Interstellar