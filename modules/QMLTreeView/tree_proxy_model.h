#ifndef QML_TREEVIEW_TREE_PROXY_MODEL_H
#define QML_TREEVIEW_TREE_PROXY_MODEL_H

#include <QSortFilterProxyModel>
#include <QString>

/**
 * \brief Main class of TreeProxyModel.
 **/
class TreeProxyModel final: public QSortFilterProxyModel {
  Q_OBJECT

 public:
  using class_name = TreeProxyModel;          //!< Alias of class name
  using inherited = QSortFilterProxyModel;    //!< Alias of inherited class

 protected:
  Q_PROPERTY(QString filter READ filter WRITE setFilter NOTIFY filterChanged)

 public:
  /**
   * \brief Parameterized ctor.
s  * \param[in] parent the Parent object
  **/
  TreeProxyModel(QObject* parent = nullptr);

  /**
   * \brief Returns the filter.
   * \return the filter.
   **/
  const QString& filter() const noexcept;

  /**
   * \brief Sets new filter.
   * \param[in] filter The filter.
   **/
  void setFilter(const QString& filter) noexcept;

  //! Return the root Model Index. Needed for the QML side.
  Q_INVOKABLE QModelIndex rootIndex();

  //! Return the depth of the item for the selected index.
  Q_INVOKABLE int depth(const QModelIndex& index) const;

  //! Remove all the elements from the tree.
  Q_INVOKABLE void clear();

  //! Remove all the elements from the tree.
  Q_INVOKABLE void reload();


 protected:
  /**
   * \brief Returns true if the item in the row indicated
             by the given source_row and source_parent should be
             included in the model; otherwise returns false.
   * \note The default implementation returns true if the value held
           by the relevant item matches the filter string, wildcard string
           or regular expression.
   * \param[in] row the Row index.
   * \param[in] index The model index.
   * \return success of this operation.
  **/
  bool filterAcceptsRow(int row, const QModelIndex& index) const final;

 Q_SIGNALS:
  void filterChanged();

 private:
  QString _filter;
};

#endif // QML_TREEVIEW_TREE_PROXY_MODEL_H
