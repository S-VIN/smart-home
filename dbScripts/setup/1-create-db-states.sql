CREATE TABLE IF NOT EXISTS statesDb
(
    id_device  SERIAL PRIMARY KEY,
    name_of_device varchar(100) not null unique,
    state bool
);

