# include<iostream>
# include<cstring>
using namespace std;
class Artist {
protected:
	char name[20];
	int date;
	char month[20];
	int year;
	char gender[20];
public:
	friend istream& operator>>(istream& input, Artist& a) {
		cin.ignore();
		cout << "Enter Artist name ->";
		input.getline(a.name, 20);
		cout << endl;
		cout << "Enter Artist Date of Birth " << endl;
		cout << "DATE -> ";
		input >> a.date;
		cout << "MONTH -> ";
		input >> a.month;
		cout << "YEAR -> ";
		input >> a.year;
		cout << endl;
		cout << "Enter Artist gender -> ";
		input >> a.gender;
		return input;
	}
	virtual void ShowDetails() {
		cout << "*******************************" << endl;
		cout << "Artist name is ->";
		cout << name << endl;
		cout << "Artist Date of Birth is -> ";
		cout << date << " " << month << " " << year << endl;
		cout << "Artist gender is-> " << gender << endl;
	}
};
class song {
protected:
	char title[100];
	char genre[50];
	char language[20];
	char duration[100];
	char album[100];
public:
	friend istream& operator>>(istream& input, song &a) {
		cin.ignore();
		cout << "Enter title of song ->";
		input.getline(a.title, 100);
		cout << "Enter genre of song -> ";
		input.getline(a.genre, 50);
		cout << "Enter language of song -> ";
		input.getline(a.language, 20);
		cout << "Enter duration of song -> ";
		input.getline(a.duration, 100);
		cout << "Enter album of song -> ";
		input.getline(a.album, 100);
		return input;
	}
	friend ostream& operator<<(ostream& output, const song a) {
		cout << "*************************************" << endl;
		cout << "Songs name -> ";
		output << a.title;
		cout << endl;
		cout << "Genre of song -> ";
		output << a.genre;
		cout << endl;
		cout << "Language of song -> ";
		output << a.language;
		cout << endl;
		cout << "Duration of song -> ";
		output << a.duration;
		cout << endl;
		cout << "Album of song -> ";
		output << a.album;
		cout << endl;
		return output;
	}
};
class movie {
protected:
	char title[100];
	char genre[100];
	char language[100];
	char duration[100];
	char production[100];
public:
	friend istream& operator>>(istream& input,  movie &a) {
		cin.ignore();
		cout << "Enter title of movie ->";
		input.getline(a.title, 100);
		cout << "Enter genre of movie -> ";
		input.getline(a.genre, 50);
		cout << "Enter language of movie -> ";
		input.getline(a.language, 20);
		cout << "Enter duration of movie -> ";
		input.getline(a.duration, 100);
		cout << "Enter production of movie -> ";
		input.getline(a.production, 100);
		return input;
	}
	friend ostream& operator<<(ostream& output, const movie a) {
		cout << "*************************************" << endl;
		cout << "Movie name -> ";
		output << a.title;
		cout << endl;
		cout << "Genre of movie -> ";
		output << a.genre;
		cout << endl;
		cout << "Language of movie -> ";
		output << a.language;
		cout << endl;
		cout << "Duration of movie -> ";
		output << a.duration;
		cout << endl;
		cout << "production of movie -> ";
		output << a.production;
		cout << endl;
		return output;
	}
};
class Singer :public Artist {
protected:
	int NumberOfSongs;
	Artist aobj;
	song* obj;
public:
	Singer() {
		NumberOfSongs = 0;
		obj = new song[NumberOfSongs];
	}
	void ShowDetails() {
		aobj.ShowDetails();
	}
	void AddSong() {
		cin >> aobj;
		cout << "Enter number of songs you want to add -> " << endl;
		cin >> NumberOfSongs;
		obj = new song[NumberOfSongs];
		cout << "INPUT SONG DETAILS " << endl;
		for (int i = 0; i < NumberOfSongs; i++) {
			cin >> obj[i];
		}
	}
	void RemoveSong() {
		char choice;
		int remove;
		cout << endl;
		for (int i = 0; i < NumberOfSongs; i++) {
			cout << "SONG " << i + 1 << " -> ";
			cout<<obj[i];
		}
		cout << "Do you want to delete a song (y/n)";
		cin >> choice;
		if (choice == 'y') {
			cout << "Enter which number of song you want to delete ->";
			cin >> remove;
			if (remove > 0) {
				for (int k = remove - 1; k < NumberOfSongs; k++) {
					obj[k] = obj[k + 1];

				}
				NumberOfSongs--;
			}
		}
	}
	
	void ShowSongs() {
		cout << "*****************************************" << endl;
		cout << "*** Your remaining songs are ***" << endl;
		for (int i = 0; i < NumberOfSongs; i++) {

			cout << obj[i];
			cout << endl;
		}
	}
};
class Actor :public Artist {
protected:
	int NumberOfMovies;
	movie* obj1;
	Artist aobj;
public:
	Actor() {
		NumberOfMovies = 0;
		obj1 = new movie[NumberOfMovies];
	}
	void ShowDetails() {
		aobj.ShowDetails();
	}
	void AddMovie() {
		cin>>aobj;
		cout << "Enter number of movies you want to add -> " << endl;
		cin >> NumberOfMovies;
		obj1 = new movie[NumberOfMovies];
		cout << "INPUT MOVIE DETAILS " << endl;
		for (int i = 0; i < NumberOfMovies; i++) {
			cin >> obj1[i];
		}
	}
	void RemoveMovie() {
		char choice;
		int remove;
		cout << endl;
		for (int i = 0; i < NumberOfMovies; i++) {
			cout << "MOVIE " << i + 1 << " -> ";
			cout<<obj1[i];
		}
		cout << "Do you want to delete a movie (y/n)";
		cin >> choice;
		if (choice == 'y') {
			cout << "Enter which number of movie you want to delete ->";
			cin >> remove;
			if (remove > 0) {
				for (int k = remove - 1; k < NumberOfMovies; k++) {
					obj1[k] = obj1[k + 1];

				}
				NumberOfMovies--;
			}
		}
	}
	void ShowMovies() {
		cout << "**************************************" << endl;
		cout << "*** Your remaining movies are ***" << endl;
		for (int i = 0; i < NumberOfMovies; i++) {
			cout<<obj1[i];
			cout << endl;
		}
	}
};
class Writer :public Artist {
protected:
	int NumberOfSongs;
	int NumberOfMovies;
	song* sobj;
	movie* mobj1;
	Artist aobj;
public:
	void ShowDetails() {
		aobj.ShowDetails();
	}
	void AddSong() {
		cin >> aobj;
		cout << "Enter number of songs you want to add -> " << endl;
		cin >> NumberOfSongs;
		sobj = new song[NumberOfSongs];
		cout << "INPUT SONG DETAILS " << endl;
		for (int i = 0; i < NumberOfSongs; i++) {
			cin >> sobj[i];
		}
	}
	void RemoveSong() {
		char choice;
		int remove;
		cout << endl;
		for (int i = 0; i < NumberOfSongs; i++) {
			cout << "SONG " << i + 1 << " -> ";
			cout << sobj[i];
		}
		cout << "Do you want to delete a song (y/n)";
		cin >> choice;
		if (choice == 'y') {
			cout << "Enter which number of song you want to delete ->";
			cin >> remove;
			if (remove > 0) {
				for (int k = remove - 1; k < NumberOfSongs; k++) {
					sobj[k] = sobj[k + 1];

				}

				NumberOfSongs--;
			}
		}
	}
		void ShowSongs() {
			cout << "*****************************************" << endl;
			cout << "*** Your remaining songs are ***" << endl;
			for (int i = 0; i < NumberOfSongs; i++) {
				cout << sobj[i];
				cout << endl;
			}
		}
	void AddMovie() {
		cout << "Enter number of movies you want to add -> " << endl;
		cin >> NumberOfMovies;
		mobj1 = new movie[NumberOfMovies];
		cout << "INPUT MOVIE DETAILS " << endl;
		for (int i = 0; i < NumberOfMovies; i++) {
			cin>>mobj1[i];
		}
	}
	void RemoveMovie() {
		char choice;
		int remove;
		cout << endl;
		for (int i = 0; i < NumberOfMovies; i++) {
			cout << "MOVIE " << i + 1 << " -> ";
			cout << mobj1[i];
		}
		cout << "Do you want to delete a movie (y/n)";
		cin >> choice;
		if (choice == 'y') {
			cout << "Enter which number of movie you want to delete ->";
			cin >> remove;
			if (remove > 0) {
				for (int k = remove - 1; k < NumberOfMovies; k++) {
					mobj1[k] = mobj1[k + 1];

				}
				NumberOfMovies--;
			}
		}
	}
	void ShowMovies() {
		cout << "**************************************" << endl;
		cout << "*** Your remaining movies are ***" << endl;
		for (int i = 0; i < NumberOfMovies; i++) {
			cout << mobj1[i];
			cout << endl;
		}
	}
};
int main() {

	Artist* ptr;
	ptr = new Artist;
	char choice;
	int art = 0;
	cout << "For how many artists you want to store your info " << endl;
	cin >> art;
	for (int i = 0; i < art; i++) {
		cout << "For which you want to store your data  (s for singer, a for actor , w for writer)" << endl;
		cin >> choice;
		if (choice == 's') {
			Singer sobj;
			sobj.AddSong();
			sobj.RemoveSong();
			sobj.ShowSongs();
			ptr = &sobj;
		}
		else if (choice == 'a') {
			Actor aobj;
			aobj.AddMovie();
			aobj.RemoveMovie();
			aobj.ShowMovies();
			ptr = &aobj;
		}
		else if (choice == 'w') {
			Writer wobj;
			wobj.AddSong();
			wobj.RemoveSong();
			wobj.AddMovie();
			wobj.RemoveMovie();
			wobj.ShowSongs();
			wobj.ShowMovies();
			ptr = &wobj;
		}
		ptr->ShowDetails();
	}
}