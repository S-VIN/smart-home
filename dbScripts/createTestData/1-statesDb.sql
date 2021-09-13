DROP SEQUENCE IF EXISTS  public.states_sequence;
CREATE SEQUENCE IF NOT EXISTS public.states_sequence
    INCREMENT 1
    START 1
    MINVALUE 1;

INSERT INTO smarthome.public.statesdb(id_device, name_of_device, state)
VALUES
    (nextval('states_sequence'), 'socket1', true),
    (nextval('states_sequence'), 'socket2', false),
    (nextval('states_sequence'), 'socket3', true),
    (nextval('states_sequence'), 'socket4', true),
    (nextval('states_sequence'), 'socket5', true),
    (nextval('states_sequence'), 'socket6', true),
    (nextval('states_sequence'), 'socket7', true),
    (nextval('states_sequence'), 'socket8', true),
    (nextval('states_sequence'), 'socket9', true),
    (nextval('states_sequence'), 'socket0', true);