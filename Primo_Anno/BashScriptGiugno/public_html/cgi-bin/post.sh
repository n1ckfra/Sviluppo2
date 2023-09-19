#!/bin/bash
## ==========================================
## SUPSI - Ambienti Operativi - BashBLOG
## Amos Brocco, Vanni Galli
## ========================================== 
. parameters.sh
. blogfn.sh

## ==========================================
## Parsing dei dati del post
## ========================================== 
POST_ID=${parameters["pid"]}
POST_TITLE=$(get_post_title $POST_ID)
POST_AUTHOR=$(get_post_author $POST_ID)
POST_DATE=$(get_post_date $POST_ID)
POST_CONTENT=$(get_post_content $POST_ID)
POST_TAGS=$(get_post_tags $POST_ID | sed -e "s/^/#/")

## ==========================================
## Parsing dei tag più usati
## ========================================== 
MOST_USED_TAGS=""
for tag in $(get_n_most_used_tags 10); do
	MOST_USED_TAGS="<a class=\"p-2\" href=\"lookup.sh?tag=$tag\">#$tag</a> $MOST_USED_TAGS"
done

## ==========================================
## Contenuto pagina
## ========================================== 
cat << EOF
Content-type: text/html

<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Ambienti Operativi 2019 - Blog Template</title>
    <link href="../css/bootstrap.min.css" rel="stylesheet">
    <link href="../css/blog.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Playfair+Display:700,900" rel="stylesheet">
</head>

<body>
    <div class="container">
        <header class="blog-header py-3">
            <div class="row flex-nowrap justify-content-between align-items-center">
                <div class="col-2 pt-1">
                    <img src="../img/supsi.png" id="supsilogo"/>
                </div>
                
                <div class="col-8 text-center" onclick="location.href = 'index.sh';">
                    <h1>Ambienti Operativi '19</h1>
                </div>
                <div class="col-2 d-flex justify-content-end align-items-center">
                    <!-- TODO: al click sulla lente deve essere caricata la pagina results.html -->
                    <!-- mostrante solo i posts che contengono il termine cercato -->
                    <form id="searchform" action="lookup.sh"><input id="search" name="keyword" placeholder="Cerca nel contenuto..."></input></form>
                    <a class="text-muted" href="#" onclick="document.getElementById('searchform').submit();">
                        <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="mx-3"><circle cx="10.5" cy="10.5" r="7.5"></circle><line x1="21" y1="21" x2="15.8" y2="15.8"></line></svg>
                    </a>
                </div>
            </div>
        </header>
        
        <!-- TODO: qui devono apparire i 10 tags più usati -->
        <!-- al click su di un tag deve essere aperta la pagina results.html -->
        <!-- mostrante solo i posts che hanno un determinato tag -->
        <div class="nav-scroller py-1 mb-2">
            <nav class="nav d-flex justify-content-between">$MOST_USED_TAGS</nav>
        </div>
        
        <!-- TODO: qui deve apparire il post cliccato in precedenza -->
        <div class="jumbotron p-3 p-md-5 text-white rounded postbg">
            <div class="col-md-12 px-0">
                <strong class="d-inline-block mb-2 tag">$POST_TAGS</strong>
                <h1 class="display-4">$POST_TITLE</h1>
                <h5>$POST_DATE, by $POST_AUTHOR</h5>
                <p class="lead my-3">
                    $POST_CONTENT
                </p>
		<a href="edit.sh?pid=$POST_ID">Modifica</a>
            </div>
        </div>
    </div>
</div>

<footer class="blog-footer">
    <p>Ambienti Operativi - Istituto sistemi informativi e networking</p>
    <p>
	<a href="#">Torna in cima</a>
    </p>
</div>
</body>
</html>
EOF

