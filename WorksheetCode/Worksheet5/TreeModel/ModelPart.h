
#ifndef VIEWER_MODELPART_H
#define VIEWER_MODELPART_H

#include <QString>
#include <QList>
#include <QVariant>

class ModelPart {
public:
    /** Constructor
     * @param data is a List (array) of strings for each property of this item (part name and visiblity in our case
     * @param parent is the parent of this item (one level up in tree)
     */
	ModelPart( const QList<QVariant>& data, ModelPart* parent = nullptr );

	/** Destructor
	  * Needs to free array of child items
	  */
	~ModelPart();

	/** Add a child to this item.
	  * @param item Pointer to child object (must already be allocated using new)
	  */
	void appendChild( ModelPart* item );

	/** Return child at position 'row' below this item
	  * @param row is the row number (below this item)
	  * @return pointer to the item requested.
	  */
	ModelPart* child( int row );

	/** Return number of children to this item
	  * @return number of children 
	  */
	int childCount() const;

	/** Get number of data items (2 - part name and visibility string) in this case.
	  * @return number of visible data columns 
	  */
	int columnCount() const;

	/** Return the data item at a particular column for this item.
	  * i.e. either part name of visibility
	  * used by Qt when displaying tree
	  * @param column is column index
	  * @return the QVariant (represents string)
	  */
	QVariant data( int column ) const;

	/** Get pointer to parent item
	  * @return pointer to parent item
	  */
	ModelPart* parentItem();

	/** Get row index of item, relative to parent item
	  * @return row index
	  */
	int row() const;
	
private:
    QList<ModelPart*> m_childItems;		/**< List (array) of child items */
    QList<QVariant> m_itemData;			/**< List (array of column data for item */
    ModelPart* m_parentItem;			/**< Pointer to parent */
};


#endif

