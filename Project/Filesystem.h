#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include "BNode.h"
#include "List.h"
#include "Helper.h"
#include "HashTable.h"

struct TreeItem
{
    std::string value;
    TreeItem* parent;
    TreeItem* first_child;
    TreeItem* next_sibling;
    bool is_directory;

    TreeItem() : first_child(NULL), next_sibling(NULL), parent(NULL), is_directory(false) {}
    TreeItem(const std::string &value, TreeItem *parent) : first_child(NULL), next_sibling(NULL), parent(parent), value(value) {}
    TreeItem(const std::string &value, TreeItem *parent, bool is_directory) : first_child(NULL), next_sibling(NULL), parent(parent), value(value), is_directory(is_directory) {}

    TreeItem* LastChild() {
      TreeItem *next = first_child, *child = NULL;

      while (next != NULL) {
        child = next;
        next = next->next_sibling;
      }

      return child;
    }

    TreeItem* Find(const std::string &entry) {
      TreeItem *tmp = first_child;

      while (tmp != NULL && tmp->value != entry) {
        tmp = tmp->next_sibling;
      }

      return tmp;
    }

    void Add(const std::string &value, bool is_directory) {
        if (first_child == NULL) {
          first_child = new TreeItem(value, this, is_directory);
        } else {
          LastChild()->next_sibling = new TreeItem(value, this, is_directory);
        }
    }

    bool Add(const std::string &path, TreeItem *currentFolder, bool is_directory)
    {
        std::string nextFolder;
        size_t pos = path.find( '/' );

        nextFolder = ( pos != std::string::npos ) ? path.substr( 0, pos ) : "";

        if (nextFolder.length() > 0) {
          TreeItem *foundEntry;
          foundEntry = currentFolder->Find(nextFolder);

          if (foundEntry == NULL) {
            return false;
          }

          Add(path.substr(pos + 1), foundEntry);
        } else {
          if(currentFolder->Find(path) != NULL) {
            return false;
          }

          currentFolder->Add(path, is_directory);
        }

        return true;
    }

};

class Filesystem
{
private:
  TreeItem fs;
  TreeItem *cwd;
public:
  Filesystem() {
    this->cwd = &fs;
  };
  ~Filesystem() {}

  TreeItem* GetFilesystem() {
    return &this->fs;
  }

  TreeItem* GetCurrentDirectory () {
    return this->cwd;
  }

  void SetCurrentDirectory (TreeItem* item) {
    this->cwd = item;
  }

  bool IsRelative (std::string path) {
    return path[0] == '.' || path[0] != '/';
  }
};



// struct Directory {
//   Directory * parent;
//   std::string name;
//   ds::da::Vector<Directory> directories;
//   ds::da::Vector<std::string> files;
  
//   bool operator==(Directory const & rhs) const {
//     return this->name == rhs.name;
//   }

//   bool operator==(std::string const & rhs) const {
//     return this->name == rhs;
//   }

//   bool operator!=(Directory const & rhs) const {
//     return this->name != rhs.name;
//   }

//   void operator=(Directory const & rhs) {
//     if (this != &rhs) {
//       this->name = rhs.name;
//       this->parent = rhs.parent;
//       this->directories = rhs.directories;
//       this->files = rhs.files;
//     }
//   }
// };

// class Filesystem
// {
// private:
//   Directory root;
//   Directory* cwd;
// public:
//   Filesystem() {};
//   ~Filesystem() {};

//   bool IsRelative (std::string path) {
//     return path[0] == '.' || path[0] != '/';
//   }

//   void CreateDirectory(ds::da::Vector<std::string> pathParts) {
//     std::string name = pathParts[pathParts.Size() - 1];
//     pathParts.RemoveLast();

//     if (pathParts.Size() > 1) {
//       Directory *tmp = &root;

//       while (!pathParts.IsEmpty()) {
//         if (tmp->directories.Contains(Directory{NULL, pathParts[0]})) {
//           tmp = &tmp->directories[tmp->directories.IndexOf(Directory{NULL, pathParts[0]})];
//         } else {
//           tmp = NULL;
//         }

//         pathParts.RemoveFirst();
//       }

//       if (tmp != NULL) {
//         tmp->directories.Insert(Directory{tmp, name});
//       }
//     } else {
//       if (root.directories.Contains(Directory{NULL, name})) {
//         throw "Directory already exists";
//       }
//       root.directories.Insert(Directory{&root, name});
//     }
//   }
// };


#endif