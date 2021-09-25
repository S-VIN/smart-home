package connectors

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

type Connections struct {
	servers 	[]*http.ServeMux
}


func headers(w http.ResponseWriter, req *http.Request) {
	body, err := ioutil.ReadAll(req.Body)
	if err != nil {
		panic(err)
	}
	fmt.Println(string(body))
}

func (conn *Connections)Init(){
	http.HandleFunc("/", headers)
}

func (conn *Connections)NewConnection(port string){
	conn.servers = append(conn.servers, http.NewServeMux())
	last := len(conn.servers) - 1
	http.ListenAndServe(port, conn.servers[last])
}


//func hello(w http.ResponseWriter, req *http.Request) {
//
//	fmt.Fprintf(w, "hello\n")
//}

