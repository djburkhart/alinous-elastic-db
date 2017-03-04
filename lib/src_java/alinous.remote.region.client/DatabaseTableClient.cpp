#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
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
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
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
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IntKey.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
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
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
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
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.remote.db.command.data/StorageNodeData.h"
#include "alinous.remote.db.command.data/TableClusterData.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/TableIndexMetadata.h"
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
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
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
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
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
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.command.data/RegionInfoData.h"
#include "alinous.remote.region.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.command.data/ClientTableData.h"
#include "alinous.remote.region.command.data/ClientSchemaData.h"
#include "alinous.remote.region.command.data/ClientStructureMetadata.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config.remote/MonitorRef.h"
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
#include "alinous.remote.region.command/AbstractNodeRegionCommand.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.remote.region.client/RegionConnectionInfo.h"
#include "alinous.remote.region.client/RegionConnection.h"
#include "alinous.remote.region.client/RegionClientConnectionFactory.h"
#include "alinous.remote.region.client/RemoteTableScheme.h"
#include "alinous.remote.region.client/RemoteRegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.db/MonitorAccess.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.system.config.remote/Regions.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
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
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.buffer/HashArrayListIterator.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table.lockmonitor/ThreadLocker.h"
#include "alinous.remote.region.command.dml/ClientFinishInsertCommitSession.h"
#include "alinous.remote.region.command.dml/ClientInsertDataCommand.h"
#include "alinous.remote.region.client/DatabaseTableClient.h"
#include "alinous.remote.region.client/RemoteClientTrxRecordsCache.h"

namespace alinous {namespace remote {namespace region {namespace client {





bool DatabaseTableClient::__init_done = __init_static_variables();
bool DatabaseTableClient::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseTableClient", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseTableClient::DatabaseTableClient(String* schema, String* name, TableMetadata* metadata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseTable(ctx), tableId(nullptr), regionAccessPool(nullptr), metadata(nullptr), schema(nullptr), name(nullptr), fullName(nullptr), indexes(GCUtils<ArrayList<IScannableIndex> >::ins(this, (new(ctx) ArrayList<IScannableIndex>(ctx)), ctx, __FILEW__, __LINE__, L"")), primaryIndex(nullptr)
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
	__GC_MV(this, &(this->fullName), this->schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(this->name, ctx), String);
	__GC_MV(this, &(this->regionAccessPool), regionAccessPool, SocketConnectionPool);
}
void DatabaseTableClient::__construct_impl(String* schema, String* name, TableMetadata* metadata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
	__GC_MV(this, &(this->fullName), this->schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(this->name, ctx), String);
	__GC_MV(this, &(this->regionAccessPool), regionAccessPool, SocketConnectionPool);
}
 DatabaseTableClient::~DatabaseTableClient() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseTableClient::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseTableClient", L"~DatabaseTableClient");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->regionAccessPool, this);
	regionAccessPool = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->fullName, this);
	fullName = nullptr;
	__e_obj1.add(this->indexes, this);
	indexes = nullptr;
	__e_obj1.add(this->primaryIndex, this);
	primaryIndex = nullptr;
	if(!prepare){
		return;
	}
}
void DatabaseTableClient::updateMetadata(TableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
}
Integer* DatabaseTableClient::getTableId(ThreadContext* ctx) throw() 
{
	return this->tableId;
}
int DatabaseTableClient::getColumnCount(ThreadContext* ctx) throw() 
{
	return this->metadata->getColumnCount(ctx);
}
IScannableIndex* DatabaseTableClient::getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	IScannableIndex* matchedindex = nullptr;
	if(matchIndexByIdList(this->primaryIndex->getColumns(ctx), columns, ctx))
	{
		return this->primaryIndex;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		ArrayList<TableColumnMetadata>* columnsMetadataList = index->getColumns(ctx);
		bool match = matchIndexByIdList(columnsMetadataList, columns, ctx);
		if(columnsMetadataList->size(ctx) == columns->size(ctx) && match)
		{
			return index;
		}
				else 
		{
			if(match)
			{
				matchedindex = index;
			}
		}
	}
	return matchedindex;
}
IScannableIndex* DatabaseTableClient::getPrimaryIndex(ThreadContext* ctx) throw() 
{
	return this->primaryIndex;
}
TableMetadata* DatabaseTableClient::getMetadata(ThreadContext* ctx) throw() 
{
	return this->metadata;
}
IDatabaseRecord* DatabaseTableClient::loadRecord(long long position, ThreadContext* ctx)
{
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getAbailableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	if(this->primaryIndex->isAvailable(columns, ctx))
	{
		return this->primaryIndex;
	}
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		if(index->isAvailable(columns, ctx))
		{
			return index;
		}
	}
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	if(this->primaryIndex->isAvailableByScanId(columns, ctx))
	{
		return this->primaryIndex;
	}
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		if(index->isAvailableByScanId(columns, ctx))
		{
			return index;
		}
	}
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	IScannableIndex* matchedindex = nullptr;
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		ArrayList<TableColumnMetadata>* columnsMetadataList = index->getColumns(ctx);
		bool matched = matchIndexByStrList(columnsMetadataList, columns, ctx);
		if(columnsMetadataList->size(ctx) == columns->size(ctx) && matched)
		{
			return index;
		}
				else 
		{
			if(matched)
			{
				matchedindex = index;
			}
		}
	}
	return matchedindex;
}
IThreadLocker* DatabaseTableClient::newThreadLocker(String* fullName, ThreadContext* ctx) throw() 
{
	return (new(ctx) ThreadLocker(fullName, ctx));
}
void DatabaseTableClient::updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
bool DatabaseTableClient::hasLaterVersion(long long oid, long long currentId, ThreadContext* ctx)
{
	return false;
}
bool DatabaseTableClient::hasLaterVersionBefore(long long oid, long long maxCommitId, long long currentCommitId, ThreadContext* ctx)
{
	return false;
}
String* DatabaseTableClient::getName(ThreadContext* ctx) throw() 
{
	return this->name;
}
void DatabaseTableClient::open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::lockStorage(ThreadContext* ctx)
{
}
void DatabaseTableClient::unlockStorage(ThreadContext* ctx)
{
}
ArrayList<IScannableIndex>* DatabaseTableClient::getIndexes(ThreadContext* ctx) throw() 
{
	return indexes;
}
void DatabaseTableClient::insertData(DbTransaction* trx, IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
}
void DatabaseTableClient::insertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			finishCommitSession(trx, newCommitId, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			ArrayList<IDatabaseRecord>* list = (new(ctx) ArrayList<IDatabaseRecord>(ctx));
			int maxLoop = records->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IDatabaseRecord* rec = records->get(i, ctx);
				list->add(rec, ctx);
				int num = i + 1;
				if(num % 200 == 0)
				{
					doInsertData(trx, records, newCommitId, ctx);
					list->clear(ctx);
				}
			}
			if(!list->isEmpty(ctx))
			{
				doInsertData(trx, list, newCommitId, ctx);
			}
		}
		catch(...){throw;}
	}
}
void DatabaseTableClient::updateData(IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
}
void DatabaseTableClient::createIndex(String* getindexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::close(ThreadContext* ctx) throw() 
{
}
String* DatabaseTableClient::getFullName(ThreadContext* ctx) throw() 
{
	return this->fullName;
}
bool DatabaseTableClient::matchIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	if(maxLoop > columnsMetadataList->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* requiredColumn = columns->get(i, ctx);
		TableColumnMetadata* metadata = columnsMetadataList->get(i, ctx);
		if(!metadata->name->equals(requiredColumn->getColumn(ctx), ctx))
		{
			return false;
		}
	}
	return true;
}
bool DatabaseTableClient::matchIndexByStrList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* requiredColumn = columns->get(i, ctx);
		TableColumnMetadata* metadata = columnsMetadataList->get(i, ctx);
		if(!metadata->name->equals(requiredColumn, ctx))
		{
			return false;
		}
	}
	return true;
}
void DatabaseTableClient::finishCommitSession(DbTransaction* trx, long long newCommitId, ThreadContext* ctx)
{
	ClientFinishInsertCommitSession* cmd = (new(ctx) ClientFinishInsertCommitSession(ctx));
	cmd->setCommitId(newCommitId, ctx);
	cmd->setTrxId(trx->getVersionContext(ctx)->getTrxId(ctx), ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->regionAccessPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->regionAccessPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			cmd->sendCommand(socket, ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3593(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3593(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3593(), e, ctx));
		}
	}
}
void DatabaseTableClient::doInsertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, ThreadContext* ctx)
{
	ClientInsertDataCommand* cmd = (new(ctx) ClientInsertDataCommand(ctx));
	cmd->setCommitId(newCommitId, ctx);
	cmd->setTable(this->name, ctx);
	cmd->setSchema(this->schema, ctx);
	cmd->setVctx(trx->getVersionContext(ctx), ctx);
	ArrayList<ClientNetworkRecord>* list = cmd->getList(ctx);
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		ClientNetworkRecord* netRec = 0;
		{
			try
			{
				netRec = (new(ctx) ClientNetworkRecord(rec, ctx));
			}
			catch(VariableException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3594(), e, ctx));
			}
		}
		list->add(netRec, ctx);
	}
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->regionAccessPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->regionAccessPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			cmd->sendCommand(socket, ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), e, ctx));
		}
	}
}
}}}}

