package connectors

import (
	"encoding/json"
	"errors"
	"fmt"
	"net/http"
)

type Connections struct {
	servers 	[]http.Server
	quantity    int
}

var Conn Connections

type employee struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

type Handler struct {
}

var handler Handler

func (Handler)ServeHTTP(w http.ResponseWriter, r *http.Request) {
	headerContentTtype := r.Header.Get("Content-Type")
	if headerContentTtype != "application/json" {
		errorResponse(w, "Content Type is not application/json", http.StatusUnsupportedMediaType)
		return
	}

	var e employee
	var unmarshalErr *json.UnmarshalTypeError

	decoder := json.NewDecoder(r.Body)
	decoder.DisallowUnknownFields()
	err := decoder.Decode(&e)
	if err != nil {
		if errors.As(err, &unmarshalErr) {
			errorResponse(w, "Bad Request. Wrong Type provided for field "+unmarshalErr.Field, http.StatusBadRequest)
		} else {
			errorResponse(w, "Bad Request "+err.Error(), http.StatusBadRequest)
		}
		return
	}
	errorResponse(w, "Success", http.StatusOK)
	fmt.Println(e)
	return
}

func NewConnection(port string){
	s := http.Server{
		Addr: port,
		Handler: handler,
	}
	Conn.servers = append(Conn.servers, s)
	last := len(Conn.servers) - 1
	Conn.servers[last].ListenAndServe()
	Conn.quantity++
}

func errorResponse(w http.ResponseWriter, message string, httpStatusCode int) {
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(httpStatusCode)
	resp := make(map[string]string)
	resp["message"] = message
	jsonResp, _ := json.Marshal(resp)
	w.Write(jsonResp)
}