---
title: Linked list
tags: 
 - list
 - ADT
description: 링크드 리스트와 ADT 설명
---

# 링크드 리스트

## 링크드 리스트의 형태

링크드 리스트는 리스트를 구현하는 여러 가지 기법 중에서도 가장 간단한 방법으로 꼽히는 자료구조다. 링크드 리스트는 **노드를 연결해서 만든 리스트**라고 해서 붙여진 이름이다. 링크드 리스트의 노드는 다음과 같이 데이터를 보관하는 필드, 다음 노드와 연결 고리 역할을 하는 포인터로 이루어진다.

![Node Img]({{ site.baseurl }}/assets/img/structure/list/node.png)

데이터와 포인터로 이루어진 노드들을 다음 그림처럼 모두 엮으면 링크드 리스트가 된다.

![Linked list]({{ site.baseurl }}/assets/img/structure/list/linked-list.png)

앞서 설명한대로 리스트는 다뤄야 하는 데이터 집합의 크기를 미리 알지 못해도 데이터가 늘어날 때마다 노드를 만들어 테일에 붙이면 되는 자료구조다. 리스트 사이에 새로운 노드를 끼워 넣거나 제거하기도 해당 노드를 가르키는 포인터만 교환하면 되기 때문에 쉬운 편이다. 

## 링크드 리스트의 노드 표현

노드 구조체는 다음과 같이 작성하고 인스턴스화 할수 있다.
{% highlight c++ %}
typedef int ElementType;

typedef struct tagNode
{
  ElementType Data; // 데이터
  struct tagNode* NextNode; // 다음 노드
} Node;

Node MyNode; // 인스턴스화
{% endhighlight %}

> ElementType은 int지만 추후 필요한 자료형으로 변경하면 된다.

## 링크드 리스트의 주요 연산

링크드 리스트에는 두 종류의 연산이 필요하다. 첫 번째는 자료구조를 구축하기 위한 연산이고, 두 번째는 자료구조에 저장된 데이터를 활용하기 위한 연산이다. 

- 노드 생성(CreateNode)/소멸(DestroyNode)
- 노드 추가(AppendNode)
- 노드 탐색(GetNodeAt)
- 노드 삭제(RemoveNode)
- 노드 삽입(InsertAfter, InsertNewHead)

노드 생성/소멸, 추가, 삭제, 삽입은 링크드 리스트 자료구조를 구축하기 위한 연산이고 탐색은 구축된 링크드 리스트의 데이터를 활용하기 위한 연산이다.

> 노드 소멸은 노드를 메모리에서 없애는 연산을 말하고, 노드 삭제는 리스트에서 노드를 제외하는 연산을 말한다.

## 노드 생성/소멸 연산

### 노드의 생성 영역

링크드 리스트의 노드는 C 언어로 작성된 프로그램의 세 가지 메모리 영역중(정적 메모리, 자동 메모리, 자유 저장소) **자유 저장소**에 생성해야 하는데 그 이유는 다음의 코드를 보면 알 수 있다.

{% highlight c++ %}
Node* SLL_CreateNode( ElementType NewData )
{
  Node NewNode; // 자동 메모리에 새로운 노드 생성
  NewNode.Data = NewData;
  NewNode.NextNode = NULL;

  return &NewNode; // NewNode가 생성된 메모리의 주소를 반환
  
} // 함수가 종료되면서 NewNode는 자동 메모리에서 제거된다.
...
Node* MyNode = SLL_CreateNode( 117 ); // MyNode는 할당되지 않은 메모리를 가리킨다.
{% endhighlight %}

이 코드를 살펴보면 SLL_CreateNode() 함수가 가장 먼저 지역 변수 NewNode를 자동 메모리(스택)에 생성하고 NewData의 Data, NextNode 필드를 초기화 한다. 그리고 함수 끝에서 NewNode의 주소를 반환한다.<br/>

문제는 return 문이 실행된 후에 MyNode 포인터는 NewNode가 '존재하는' 메모리의 주소를 갖고 있는 것이 아니라 자동 메모리에 의해 제거된 NewNode가 '존재했던' 메모리의 주소를 담고 있다는 것이다.<br/>

이미 사라져 버린 NewNode의 주소를 담고 있는 MyNode 포인터가 프로그램을 죽여버리거나 예기치 않은 동작을 발생시킬수 있다.

### 노드의 생성은 자유 저장소에

자유 저장소를 활용하려면 메모리를 할당하는 malloc() 함수(memory allocation의 약자)가 필요하다.

{% highlight c++ %}
void* malloc( size_t size );
{% endhighlight %}

반환 형식은 void* 인데 이는 모든 형식의 메모리를 가리킬 수 있는 포인터다. malloc()은 얼마나 큰 공간을 할당할지를 다루는 함수이고, 그 안에 어떤 형식의 데이터가 담기는지에 대해서는 관심이 없기 때문에 void* 는 이 함수가 할당하는 자유 저장소의 메모리 주소를 가리키기에 적합한 형식이다.

malloc()의 매개 변수는 size 하나뿐이다. size는 malloc()이 할당해야 하는 메모리의 크기를 나타낸다. 이 매개 변수의 형식은 size_t인데 sizeof 연산자의 반환형이기도 한 size_t는 사실 typedef로 선언한 unsigned int의 별칭이다.
malloc() 함수를 사용하여 노드를 자유 저장소에 생성하는 예제는 다음과 같다.

{% highlight c++ %}
Node* NewNode = (Node*)malloc(sizeof(Node));
{% endhighlight %}

이 예제에서 malloc() 함수는 sizeof 연산자가 측정한 노드 구조체의 크기만 한 메모리를 자유 저장소에 확보하고 NewNode 포인터에 그 메모리 주소를 저장한다.

### malloc()을 이용하여 자유 저장소에 노드 생성

{% highlight c++ %}
Node* SLL_CreateNode(ElementType NewData)
{
  Node* NewNode = (Node*)malloc(sizeof(Node));

  NewNode->Data = NewData; // 데이터를 저장한다.
  NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화한다.

  return NewNode; // 노드의 주소를 반환한다.
}
{% endhighlight %}

### 노드의 소멸

노드를 소멸시킬려면 free() 함수에 노드가 있는 메모리 주소를 알려주면 된다.

{% highlight c++ %}
void free( void *memblock );
{% endhighlight %}

다음은 노드를 소멸하는 SLL_DestroyNode()함수다. 노드가 존재하는 주소를 가리키는 포인터를 입력받아 free() 함수에 넘겨 해당 노드를 소멸시킨다.

{% highlight c++ %}
void SLL_DestroyNode(Node* Node)
{
  free(Node);
}
{% endhighlight %}

## 노드 추가 연산

노드 추가는 링크드 리스트의 테일 노드 뒤에 새로운 노드를 만들어 연결하는 연산이다.<br/>
작성중...

<!-- ### Search

The entire site, including posts and documentation, is indexed and then available
for search at the top or side of the page. Give it a try! The content is rendered
into window data that is used by lunr.js to generate the search results.
If you want to exclude any file from search, add this to its front end matter:

```
---
layout: null
excluded_in_search: true
---
```

The example above is for a javascript file in the assets folder that is used as a template,
but should not be included in search.

### External Search

If you have an external site with a search GET endpoint (meaning one that ends
in `?q=<term>`, then you can automatically link page tags to search this endpoint.
For example, on an HPC site I'd want a tag like "mpi" to do a search on 
[http://ask.cyberinfrastructure.org](http://ask.cyberinfrastructure.org) for mpi.
See the [tags](#tags) section below for how to configure this.

### Documentation

Documentation pages should be written in the `docs` folder of the repository,
and you are allowed to use whatever level of nesting (subfolders) that 
works for you! It's a Jekyll [collection](https://jekyllrb.com/docs/collections/), which means that you
can add other content (images, scripts) and it will be included for linking to.
To create subfolders with files, you can simply create new markdon files. For example:

 - `_docs/subfolder/example-page.md` renders to `http://localhost:4000/docsy-jekyll/docs/subfolder/example-page/`
 - `_docs/subfolder.md` renders to `http://localhost:4000/docsy-jekyll/docs/subfolder/`

And the page you are reading now renders from `_docs/getting-started.md`

#### Organization

The url that will render is based on the path. For example, if we had the following structure:

```
docs/
  getting-started.md
  clusters/
     sherlock/
         getting-started.md
```

The first page (akin to the one you are reading) would render at it's path,
`/docs/getting-started/`.


#### Linking

From that page, we could provide the
direct path in markdown to any subfolder to link to it, such as the second
getting started page for sherlock:

```
{% raw %}[example](clusters/sherlock/getting-started.md){% endraw %}
```

[Here](example-page) is an example link to a relative path of a file (`example-page.md`)
in the same directory, and from that page you can test linking to a subfolder.
In the case of not having a subfolder, we could write the link out directly:

```
{% raw %}[example]({{ site.baseurl }}/docs/clusters/sherlock/getting-started.md){% endraw %}
```

or just put the relative path:

```
{% raw %}[Here](example-page){% endraw %}
```

or better, there is a shortand trick! We can use the provided "includes" 
template to do the same based on the path to create a link:

```
{% raw %}{% include doc.html name="Sherlock Cluster" path="clusters/sherlock/getting-started" %}{% endraw %}
```
The path should be relative to the docs folder.

### Pages

The `pages` folder uses the same page layout, but is not part of the docs collection.
The two are provided to create a distinction between website pages (e.g., about,
feed.xml) and documentation pages.  

### Navigation

Whether you place your page under "pages" or "docs," for those pages that you want added to the navigation, 
you should add them to `_data/toc.yml`. If you've defined a `permalink` in the
front end matter, you can use that (e.g., "About" below). If you haven't and
want to link to docs, the url is the path starting with the docs folder.
Here is an example (currently the active example):

```yaml
- title: Documentation
  url: docs
  links:
    - title: "Getting Started"
      url: "docs/getting-started"
      children:
        - title: Features
          url: "docs/getting-started#getting-started"
        - title: Development
          url: "docs/getting-started#development"
        - title: Customization
          url: "docs/getting-started#customization"
    - title: "Extras"
      url: "docs/extras"
      children:
        - title: Quizzes
          url: "docs/extras/example-quiz"
    - title: "About"
      url: "about"
    - title: "News"
      url: "news
```

If you want to add an external url for a parent or child, do this:

```yaml
  - title: GitHub Repository
    external_url: https://www.github.com/vsoch/mkdocs-jekyll
```

### News Posts

It might be the case that your site or group has news items that would
warrant sharing with the community, and should be available as a feed.
For this reason, you can write traditional [posts](https://jekyllrb.com/docs/posts/) in the `_posts`
folder that will parse into the site [feed]({{ site.baseurl }}/feed.xml)
The bottom of the page links the user to a post archive, where posts are organized
according to the year.

### Buttons

Buttons come in a nice array of colors. Here is the code for a basic example,
and you'd want to vary the `.btn-<tag>` to get different classes.

```html
<button class="btn btn-success">.btn-success</button>
```

<button class="btn btn-success">.btn-success</button>
<button class="btn btn-info">.btn-info</button>
<button class="btn btn-secondary">.btn-secondary</button>
<button class="btn btn-primary">.btn-primary</button>
<button class="btn btn-danger">.btn-danger</button>
<button class="btn btn-warning">.btn-warning</button>

### Badges

For news post items, it's nice to be able to tag it with something that indicates
a status, such as "warning" or "alert." For this reason, you can add badges to
the front end matter of any post page, and they will render colored by a type,
with the tag of your choice. For example, here is an example header for
a post:

```yaml
---
title:  "Two Thousand Nineteen"
date:   2019-06-28 18:52:21
categories: jekyll update
badges:
 - type: warning
   tag: warning-badge
 - type: danger
   tag: danger-badge
---
```

And here is the post preview with the rendered badges that it produces:

<span class="badge badge-warning">warning-badge</span>
<span class="badge badge-danger">danger-badge</span>

And the other badges that you can define include success, info, secondary,
and primary.

<span class="badge badge-success">success-badge</span>
<span class="badge badge-info">info-badge</span>
<span class="badge badge-secondary">secondary-badge</span>
<span class="badge badge-primary">primary-badge</span>

### Alerts

{% include alert.html type="info" title="What is an alert?" content="An alert is a box that can stand out to indicate important information. You can choose from levels success, warning, danger, info, and primary. This example is an info box, and the code for another might look like this:" %}

```
{%raw%}{% include alert.html type="info" title="Here is another!" %}{%endraw%}
```

Just for fun, here are all the types:

{% include alert.html type="warning" content="This is a warning" %}
{% include alert.html type="danger" content="This alerts danger!" %}
{% include alert.html type="success" content="This alerts success" %}
{% include alert.html type="info" content="This is useful information." %}
{% include alert.html type="primary" content="This is a primary alert" %}
{% include alert.html type="secondary" content="This is a secondary alert" %}

### Quotes

You can include block quotes to emphasize text. 

> Here is an example. Isn't this much more prominent to the user?

## Development

Initially (on OS X), you will need to setup [Brew](http://brew.sh/) which is a package manager for OS X and [Git](https://git-scm.com/). To install Brew and Git, run the following commands:

```bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew install git
```

If you are on Debian/Ubuntu, then you can easily install git with `apt-get`

```bash
apt-get update && apt-get install -y git
```

### Install Jekyll

You can also install Jekyll with brew.

```bash
$ brew install ruby
$ gem install jekyll
$ gem install bundler
$ bundle install
```

On Ubuntu I do a different method:

```bash
git clone https://github.com/rbenv/ruby-build.git ~/.rbenv/plugins/ruby-build
echo 'export PATH="$HOME/.rbenv/plugins/ruby-build/bin:$PATH"' >> ~/.bashrc
exec $SHELL
rbenv install 2.3.1
rbenv global 2.3.1
gem install bundler
rbenv rehash
ruby -v

# Rails
curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
sudo apt-get install -y nodejs
gem install rails -v 4.2.6
rbenv rehash

# Jekyll
gem install jekyll
gem install github-pages
gem install jekyll-sass-converter

rbenv rehash
```

### Get the code

You should first fork the repository to your GitHub organization or username,
and then clone it.

```bash
$ git clone https://github.com/<username>/mkdocs-jekyll.git docs
$ cd docs
```

You can clone the repository right to where you want to host the docs:

```bash
$ git clone https://github.com/<username>/mkdocs-jekyll.git docs
$ cd docs
```


### Serve

Depending on how you installed jekyll:

```bash
jekyll serve
# or
bundle exec jekyll serve
```


### Preview

We provide a [CircleCI](https://circleci.com/) configuration recipe that you
can use to preview your site on CircleCI before merging into master. You
should follow the instructions to [set up a project](https://circleci.com/docs/enterprise/quick-start/),
and then in the project settings be sure to enable building forked build requests,
and to cancel redundant builds. The preview will be built on CircleCI, and saved
to static files for you to browse. The only change you will need is to edit
the static files location to be the name of your repository, which is at te
bottom of the `.circleci/config.yml` file:

```yaml
      - store_artifacts:
          path: ~/repo/_site
          destination: mkdocs-jekyll
```

In the above, the destination should coincide with your repository name.
Remember that for most links, CircleCI won't honor an `index.html` file in a subfolder
(e.g., `subfolder/index.html` will not be served as `subfolder/`, so for example,
you might need to turn this:

```
https://<circleci>/0/mkdocs-jekyll/docs/getting-started/
```
into this:

```
https://<circleci>/0/mkdocs-jekyll/docs/getting-started/index.html
```

## Customization

#### config.yml

To edit configuration values, customize the [_config.yml](_config.yml).
Most are documented there, and please [open an issue](https://www.github.com/{{ site.github_user }}/{{ site.github_user }}/issues) if you have questions.

#### Adding pages

To add pages, write them into the [pages](pages) folder. 
You define urls based on the `permalink` attribute in your pages,
and then add them to the navigation by adding to the content of [_data/toc.yml](_data/toc.yml).

#### Tags

If you include tags on a page, by default they will link to the [tags page]({{ site.url }}{{ site.baseurl }}/tags) on the site. However, if you define a `tag_search_endpoint` url in your configuration file, by clicking
the tag, the user will be taken to this page to search for it. As an example,
we define the current search endpoint to be Ask Cyberinfrastructure, and
page tags link to a search on it:

```yaml
tag_search_endpoint: https://ask.cyberinfrastructure.org/search?q=
tag_color: danger # danger, success, warning, primary, secondary, info
```

Note that you can also choose a color! The tags appear at the top of the page,
as they do on this page. The tags should be defined like this in the front end
matter:

```yaml
tags: 
 - jekyll
 - github
```

They are appended to the first h1 block, so generally your pages should have a header.
If you comment out this variable, then each of your tags will link to it's appropriate
spot on the tags page linked above.

```yaml
#tag_search_endpoint: https://ask.cyberinfrastructure.org/search?q=
tag_color: primary # danger, success, warning, primary, info, secondary
```
 -->
