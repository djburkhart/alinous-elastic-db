#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.lock/LockObject.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.remote.db.command.data/StorageNodeData.h"
#include "alinous.remote.db.command.data/TableClusterData.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree/BTreeLeafContainer.h"
#include "alinous.btree/BTreeMaxLeafContainer.h"
#include "alinous.btree/BTreeValues.h"
#include "alinous.btree/KeyValue.h"
#include "alinous.btree/BTreeLeafNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.buffer/HashArrayListIterator.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.btree/LongKey.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/ColumnsUniqueCollections.h"
#include "alinous.lock.unique/TableUniqueCollections.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.db/MonitorAccess.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.command.data/RegionInfoData.h"
#include "alinous.system.config.remote/Regions.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.region.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.command.data/ClientTableData.h"
#include "alinous.remote.region.command.data/ClientSchemaData.h"
#include "alinous.remote.region.command.data/ClientStructureMetadata.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.remote.region/NodeReference.h"
#include "alinous.remote.region/NodeCluster.h"
#include "alinous.remote.region/NodeTableReference.h"
#include "alinous.remote.region/NodeTableClaster.h"
#include "alinous.remote.region/NodeRegionSchema.h"
#include "alinous.remote.region/RegionShardPart.h"
#include "alinous.remote.region/RegionShardTable.h"
#include "alinous.remote.region/NodeReferenceManager.h"
#include "java.lang/Long.h"
#include "alinous.remote.region/RegionInsertExecutor.h"
#include "alinous.remote.region/RegionInsertExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.runtime.dbif/DataSourceManager.h"
#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger.server/FileBreakpointContainer.h"
#include "alinous.runtime.engine.debugger/DebugStackFrame.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEventNotifier.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.parse.htmlxml/Token.h"
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/AbstractXHtmlAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/HtmlDocType.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server.webmodule/AbstractWebModule.h"
#include "alinous.server.webmodule/WebModuleList.h"
#include "alinous.server.webmodule/WebModuleHashList.h"
#include "alinous.server.webmodule/WebModuleManager.h"
#include "alinous.system.config.remote/Table.h"
#include "alinous.system.config.remote/Tables.h"
#include "alinous.system.config.remote/Node.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config/DataSourceInfo.h"
#include "alinous.system.config/MailInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.runtime.function/AlinousNativeFunctionRegistory.h"
#include "alinous.system.functions/NativeFunctionManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.system/AlinousCoreLogger.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql.expression/SQLLiteral.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLMultiplicativeExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression/SQLSubqueryExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"

namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLColumnIdentifier::__init_done = __init_static_variables();
bool SQLColumnIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLColumnIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLColumnIdentifier::SQLColumnIdentifier(AlinousName* name, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLExpression(ctx), distinct(0), id(nullptr), asName(nullptr), resolvedName(nullptr), analysedColumn(nullptr), columnOrder(-1)
{
	__GC_MV(this, &(this->id), name, AlinousName);
}
void SQLColumnIdentifier::__construct_impl(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), name, AlinousName);
}
 SQLColumnIdentifier::~SQLColumnIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLColumnIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLColumnIdentifier", L"~SQLColumnIdentifier");
	__e_obj1.add(this->id, this);
	id = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	__e_obj1.add(this->resolvedName, this);
	resolvedName = nullptr;
	__e_obj1.add(this->analysedColumn, this);
	analysedColumn = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLExpression::__releaseRegerences(true, ctx);
}
bool SQLColumnIdentifier::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->id != nullptr && !this->id->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLColumnIdentifier::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLColumnIdentifier::isDistinct(ThreadContext* ctx) throw() 
{
	return distinct;
}
void SQLColumnIdentifier::setDistinct(bool distinct, ThreadContext* ctx) throw() 
{
	this->distinct = distinct;
}
AlinousName* SQLColumnIdentifier::getId(ThreadContext* ctx) throw() 
{
	return id;
}
void SQLColumnIdentifier::setId(AlinousName* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, AlinousName);
}
String* SQLColumnIdentifier::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void SQLColumnIdentifier::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
IAlinousVariable* SQLColumnIdentifier::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->resolvedName == nullptr)
	{
		__GC_MV(this, &(this->resolvedName), (new(ctx) VariantValue(this->id->toString(ctx), ctx)), VariantValue);
	}
	return this->resolvedName;
}
bool SQLColumnIdentifier::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
ExpressionSourceId* SQLColumnIdentifier::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(this->id->toString(ctx), this, nullptr, ctx));
}
bool SQLColumnIdentifier::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	ArrayList<String>* segments = this->id->getSegments(ctx);
	__GC_MV(this, &(this->analysedColumn), nullptr, ScanTableColumnIdentifier);
	if(analyzeAsName(context, segments, ctx))
	{
		return true;
	}
	int size = this->id->getSegments(ctx)->size(ctx);
	String* schema = nullptr;
	String* table = nullptr;
	String* column = nullptr;
	switch(size) {
	case 1:
		schema = ConstStr::getCNST_STR_955();
		column = segments->get(0, ctx);
		table = SQLAnalyseContext::findTable(context, schema, column, ctx);
		if(table == nullptr)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1044()->clone(ctx)->append(this->id->toString(ctx), ctx), ctx));
		}
		break ;
	case 2:
		schema = ConstStr::getCNST_STR_955();
		table = segments->get(0, ctx);
		column = segments->get(1, ctx);
		break ;
	case 3:
		schema = segments->get(0, ctx);
		table = segments->get(1, ctx);
		column = segments->get(2, ctx);
		break ;
	default:
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1044()->clone(ctx)->append(this->id->toString(ctx), ctx), ctx));
		break;
	}
	IDatabaseTable* dataStore = context->getDatabase(ctx)->getTable(schema, table, ctx);
	if(dataStore == nullptr)
	{
		throw (new(ctx) DatabaseException(schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	TableAndSchema* tableSc = (new(ctx) TableAndSchema(schema, table, ctx));
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(tableSc, this->asName, dataStore->getColumnCount(ctx), ctx));
	__GC_MV(this, &(this->analysedColumn), (new(ctx) ScanTableColumnIdentifier(tableId, column, ctx)), ScanTableColumnIdentifier);
	analyseColumnOrder(tableSc, context, ctx);
	return true;
}
bool SQLColumnIdentifier::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->analysedColumn->getTable(ctx)->equals(table, ctx);
}
ArrayList<ScanTableColumnIdentifier>* SQLColumnIdentifier::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list->add(this->analysedColumn, ctx);
	return list;
}
bool SQLColumnIdentifier::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLColumnIdentifier::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLColumnIdentifier::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLColumnIdentifier::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return true;
}
ScanTableColumnIdentifier* SQLColumnIdentifier::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return this->analysedColumn;
}
VariantValue* SQLColumnIdentifier::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->columnOrder >= 0)
	{
		ScanTableIdentifier* tableId = analysedColumn->getTable(ctx);
		return record->getValueOfTable(tableId, this->columnOrder, ctx);
	}
		else 
	{
	}
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool SQLColumnIdentifier::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLColumnIdentifier::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
bool SQLColumnIdentifier::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
int SQLColumnIdentifier::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLColumnIdentifier;
}
void SQLColumnIdentifier::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->distinct = buff->getBoolean(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->id), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void SQLColumnIdentifier::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLColumnIdentifier, ctx);
	buff->putBoolean(this->distinct, ctx);
	bool isnull = (this->id == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->id->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
int SQLColumnIdentifier::fileSize(ThreadContext* ctx) throw() 
{
	int total = 4;
	total += 1;
	bool isnull = (this->id == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->id->fileSize(ctx);
	}
	isnull = (this->asName == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->asName->length(ctx) * 2 + 4;
	}
	return total;
}
void SQLColumnIdentifier::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IExpressionFactory::__SQLColumnIdentifier, ctx);
	builder->putBoolean(this->distinct, ctx);
	bool isnull = (this->id == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->id->toFileEntry(builder, ctx);
	}
	isnull = (this->asName == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->asName, ctx);
	}
}
void SQLColumnIdentifier::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	this->distinct = fetcher->fetchBoolean(ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		AlinousName* exp = AlinousName::fromFileEntry(fetcher, ctx);
		if(exp != nullptr)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->id), exp, AlinousName);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), fetcher->fetchString(ctx), String);
	}
}
void SQLColumnIdentifier::analyseColumnOrder(TableAndSchema* tableSc, SQLAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = context->getTables(ctx)->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableMetadata* tableMetadata = context->getTables(ctx)->get(i, ctx);
		String* s = tableMetadata->getSchemaName(ctx);
		String* t = tableMetadata->getTableName(ctx);
		if(s->equals(tableSc->getSchema(ctx), ctx) && t->equals(tableSc->getTable(ctx), ctx))
		{
			this->columnOrder = tableMetadata->getColumnOrder(this->analysedColumn, ctx);
		}
	}
}
bool SQLColumnIdentifier::analyzeAsName(SQLAnalyseContext* context, ArrayList<String>* segments, ThreadContext* ctx) throw() 
{
	int size = segments->size(ctx);
	if(size != 2)
	{
		return false;
	}
	String* asname = segments->get(0, ctx);
	String* columnName = segments->get(1, ctx);
	ScanTableMetadata* meta = context->findTableByAsName(asname, ctx);
	if(meta == nullptr)
	{
		return false;
	}
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(nullptr, asname, meta->getColumns(ctx)->size(ctx), ctx));
	__GC_MV(this, &(this->analysedColumn), (new(ctx) ScanTableColumnIdentifier(tableId, columnName, ctx)), ScanTableColumnIdentifier);
	return true;
}
}}}}

