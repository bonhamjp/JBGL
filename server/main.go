package main

import (
	"fmt"
	"log"
	"net/http"
	"text/template"

	"github.com/bitly/go-simplejson"
	"github.com/gorilla/mux"
)

var templateDirectory string = "./views/"

func newRouter() *mux.Router {
	router := mux.NewRouter()

	staticAssetsDirectory := http.FileServer(http.Dir("./assets/"))
	router.PathPrefix("/assets").Handler(http.StripPrefix("/assets", staticAssetsDirectory))

	router.HandleFunc("/", getHomeHandler).Methods("GET")
	router.HandleFunc("/visualization/{projectId}", getVisualizerHandler).Methods("GET")

	router.HandleFunc("/user/{userId}", getUserHandler).Methods("GET")

	// router.HandleFunc("/zones", getZonesHandler).Methods("GET")
	// router.HandleFunc("/zone/{fqdn}/edit", getZoneEditHandler).Methods("GET")
	// router.HandleFunc("/zone/{fqdn}", putZoneHandler).Methods("POST")
	// router.HandleFunc("/zone/new", getNewZoneHandler).Methods("GET")
	// router.HandleFunc("/zone", postNewZoneHandler).Methods("POST")
	// router.HandleFunc("/zone/{fqdn}/delete", getZoneDeleteHandler).Methods("GET")

	// router.HandleFunc("/zone/{fqdn}/{domain}/{type}", getRecordEditHandler).Methods("GET")

	return router
}

func init() {
}

func main() {
	router := newRouter()

	http.ListenAndServe(":8080", router)
}

func generateHTML(writer http.ResponseWriter, data interface{}, templateHandles ...string) {
	// list of template files to parse
	var templateFiles []string

	for _, templateHandle := range templateHandles {
		templateFiles = append(templateFiles, fmt.Sprintf("%s%s.html", templateDirectory, templateHandle))
	}

	// parse templates
	templates := template.Must(template.ParseFiles(templateFiles...))
	templates.ExecuteTemplate(writer, "layout", data)
}

// React entrypoint
func getHomeHandler(writer http.ResponseWriter, request *http.Request) {
	// TODO: Load user data, and persist in state
	userData := "John"

	generateHTML(writer, userData, "layouts/app", "app")
}

// WebAssembly/WebGL entrypoint
func getVisualizerHandler(writer http.ResponseWriter, request *http.Request) {
	// TODO: Load user and project data, and persist in state
	userData := "John"

	generateHTML(writer, userData, "layouts/visualization", "visualization")
}

// User payload
func getUserHandler(writer http.ResponseWriter, request *http.Request) {
	json := simplejson.New()
	json.Set("visualizer", "test")

	payload, err := json.MarshalJSON()
	if err != nil {
		log.Println(err)
	}

	writer.Header().Set("Content-Type", "application/json")
	writer.Write(payload)
}
