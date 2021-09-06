#ifndef QUERY_NODES_H
#define QUERY_NODES_H

#include "QueryExecutor.h"

namespace Spino {
	// base node type
	class QueryNode {
		public:
			virtual ~QueryNode() { }
			virtual void Accept(QueryExecutor* t) = 0;
	};

	// represents a numeric value
	class NumericValue: public QueryNode {
		public:
			double value;
			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};

	// represents a string value
	class StringValue: public QueryNode {
		public: 
			std::string value;
			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};

	// represents a boolean value
	class BoolValue: public QueryNode {
		public:
			bool value;
			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};


	// contains a json pointer to the field and the operation to perform on it
	// example: field -> operation (equal) -> numericValue (10)
	// loads the field, checks if it is equal to 10
	class Field: public QueryNode {
		public:
			std::shared_ptr<Operator> operation;
			PointerType jp;

			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};

	// a logical expression such as AND or OR
	// op is the expression and may be  TOK_AND, TOK_OR
	// fields are the list of fields (with their respective operations) to load
	class LogicalExpression: public QueryNode {
		public:
			int op;
			std::vector<std::shared_ptr<QueryNode>> fields;

			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};

	// a list of query nodes
	class List: public QueryNode {
		public:
			std::vector<std::shared_ptr<QueryNode>> list;

			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};

	// an operator
	// op may be $eq, $ne, $gt, $lt, $in, $nin, $exists, $type
	// cmp is the node to perform the operation on
	// an operator always leaves a true/false on top of the stack
	class Operator: public QueryNode {
		public:
			int op;
			std::shared_ptr<QueryNode> cmp;

			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};

	class BasicFieldComparison: public QueryNode {
		public:
			PointerType jp;
			Value v;

			virtual void Accept(QueryExecutor* t) {
				t->Visit(this);
			}
	};
}


#endif


