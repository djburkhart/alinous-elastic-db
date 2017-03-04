#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
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
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
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
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
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
#include "alinous.db.table/IDatabaseRecord.h"
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
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/TableSchema.h"
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
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
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
#include "alinous.system/AlinousCoreLogger.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.function/AlinousNativeFunctionRegistory.h"
#include "alinous.system.functions/NativeFunctionManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
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
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
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
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/CatchBlock.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/ThrowStatement.h"
#include "alinous.compile.stmt/TryBlock.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"

namespace alinous {namespace compile {namespace stmt {



constexpr EnumBase __TypedVariableDeclare__VariableType::__DEFAULT_NULL;
constexpr EnumBase __TypedVariableDeclare__VariableType::BOOL_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::BYTE_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::SHORT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::CHAR_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::INT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::LONG_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::FLOAT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::DOUBLE_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::STRING_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::TIMESTAMP;
constexpr EnumBase __TypedVariableDeclare__VariableType::TIME;
constexpr EnumBase __TypedVariableDeclare__VariableType::BIGDECIMAL;
constexpr EnumBase __TypedVariableDeclare__VariableType::OBJECT_TYPE;


bool TypedVariableDeclare::__init_done = __init_static_variables();
bool TypedVariableDeclare::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclare", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TypedVariableDeclare::~TypedVariableDeclare() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TypedVariableDeclare::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclare", L"~TypedVariableDeclare");
	__e_obj1.add(this->typeName, this);
	typeName = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->initExp, this);
	initExp = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void TypedVariableDeclare::setTypeName(AlinousName* typeName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->typeName), typeName, AlinousName);
	String* strName = this->typeName->toString(ctx);
	if(strName->equals(ConstStr::getCNST_STR_957(), ctx))
	{
		this->typeEnum = VariableType::BOOL_TYPE;
	}
		else 
	{
		if(strName->equals(ConstStr::getCNST_STR_961(), ctx))
		{
			this->typeEnum = VariableType::INT_TYPE;
		}
				else 
		{
			if(strName->equals(ConstStr::getCNST_STR_965(), ctx))
			{
				this->typeEnum = VariableType::STRING_TYPE;
			}
						else 
			{
				if(strName->equals(ConstStr::getCNST_STR_958(), ctx))
				{
					this->typeEnum = VariableType::BYTE_TYPE;
				}
								else 
				{
					if(strName->equals(ConstStr::getCNST_STR_959(), ctx))
					{
						this->typeEnum = VariableType::SHORT_TYPE;
					}
										else 
					{
						if(strName->equals(ConstStr::getCNST_STR_960(), ctx))
						{
							this->typeEnum = VariableType::CHAR_TYPE;
						}
												else 
						{
							if(strName->equals(ConstStr::getCNST_STR_962(), ctx))
							{
								this->typeEnum = VariableType::LONG_TYPE;
							}
														else 
							{
								if(strName->equals(ConstStr::getCNST_STR_964(), ctx))
								{
									this->typeEnum = VariableType::FLOAT_TYPE;
								}
																else 
								{
									if(strName->equals(ConstStr::getCNST_STR_963(), ctx))
									{
										this->typeEnum = VariableType::DOUBLE_TYPE;
									}
																		else 
									{
										if(strName->equals(ConstStr::getCNST_STR_967(), ctx))
										{
											this->typeEnum = VariableType::TIMESTAMP;
										}
																				else 
										{
											if(strName->equals(ConstStr::getCNST_STR_966(), ctx))
											{
												this->typeEnum = VariableType::TIME;
											}
																						else 
											{
												if(strName->equals(ConstStr::getCNST_STR_968(), ctx))
												{
													this->typeEnum = VariableType::BIGDECIMAL;
												}
																								else 
												{
													this->typeEnum = VariableType::OBJECT_TYPE;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void TypedVariableDeclare::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
IStatement::StatementType TypedVariableDeclare::getType(ThreadContext* ctx) throw() 
{
	return StatementType::TYPED_VARIABLE_DECLARE;
}
void TypedVariableDeclare::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(this->name->getSegments(ctx)->size(ctx) != 1)
	{
		validator->addError(ConstStr::getCNST_STR_1102(), this->name, ctx);
	}
}
bool TypedVariableDeclare::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->typeName != nullptr && !this->typeName->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->initExp != nullptr && !this->initExp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool TypedVariableDeclare::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* mainFrame = context->getCurrentStack(ctx);
	SubVariableDeclareHolder* subFrame = mainFrame->getCurrentSubStack(ctx);
	subFrame->addTypedVariableDeclare(this, ctx);
	AlinousClass* clazz = nullptr;
	switch(this->typeEnum) {
	case TypedVariableDeclare::VariableType::BOOL_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::INT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::INT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::BYTE_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BYTE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::SHORT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::SHORT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::CHAR_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::CHAR_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::LONG_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::LONG_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::FLOAT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::FLOAT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::DOUBLE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::STRING_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::STRING_TYPE, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::TIMESTAMP:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::TIMESTAMP, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::TIME:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::TIME, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::BIGDECIMAL:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BIGDECIMAL, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::OBJECT_TYPE:
	default:
		clazz = context->findClassDeclare(this->typeName, ctx);
		if(clazz == nullptr)
		{
			context->getSourceValidator(ctx)->addError(this->typeName->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_969(), ctx), this, ctx);
		}
				else 
		{
			__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(clazz, ctx)), AlinousType);
			this->analysedType->setDimension(this->dimension, ctx);
		}
		break ;
	}
	if(this->initExp != nullptr)
	{
		this->initExp->analyse(context, false, ctx);
	}
	return true;
}
AlinousName* TypedVariableDeclare::getTypeName(ThreadContext* ctx) throw() 
{
	return typeName;
}
AlinousName* TypedVariableDeclare::getName(ThreadContext* ctx) throw() 
{
	return name;
}
TypedVariableDeclare::VariableType TypedVariableDeclare::getTypeEnum(ThreadContext* ctx) throw() 
{
	return typeEnum;
}
IExpression* TypedVariableDeclare::getInitExp(ThreadContext* ctx) throw() 
{
	return initExp;
}
void TypedVariableDeclare::setInitExp(IExpression* initExp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->initExp), initExp, IExpression);
}
AlinousType* TypedVariableDeclare::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
int TypedVariableDeclare::getDimension(ThreadContext* ctx) throw() 
{
	return dimension;
}
void TypedVariableDeclare::setDimension(int dimension, ThreadContext* ctx) throw() 
{
	this->dimension = dimension;
}
void TypedVariableDeclare::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->typeName), static_cast<AlinousName*>(el), AlinousName);
	}
	this->dimension = buff->getInt(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->initExp), static_cast<IExpression*>(el), IExpression);
	}
	int typeNum = buff->getInt(ctx);
	int2enum(typeNum, ctx);
}
void TypedVariableDeclare::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__TypedVariableDeclare, ctx);
	bool isnull = (this->typeName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->typeName->writeData(buff, ctx);
	}
	buff->putInt(this->dimension, ctx);
	isnull = (this->initExp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->initExp->writeData(buff, ctx);
	}
	int typeNum = enum2Int(ctx);
	buff->putInt(typeNum, ctx);
}
int TypedVariableDeclare::enum2Int(ThreadContext* ctx) throw() 
{
	switch(this->typeEnum) {
	case TypedVariableDeclare::VariableType::BOOL_TYPE:
		return 1;
	case TypedVariableDeclare::VariableType::BYTE_TYPE:
		return 2;
	case TypedVariableDeclare::VariableType::SHORT_TYPE:
		return 3;
	case TypedVariableDeclare::VariableType::CHAR_TYPE:
		return 4;
	case TypedVariableDeclare::VariableType::INT_TYPE:
		return 5;
	case TypedVariableDeclare::VariableType::LONG_TYPE:
		return 6;
	case TypedVariableDeclare::VariableType::FLOAT_TYPE:
		return 7;
	case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
		return 8;
	case TypedVariableDeclare::VariableType::STRING_TYPE:
		return 9;
	case TypedVariableDeclare::VariableType::TIMESTAMP:
		return 10;
	case TypedVariableDeclare::VariableType::TIME:
		return 11;
	case TypedVariableDeclare::VariableType::BIGDECIMAL:
		return 12;
	case TypedVariableDeclare::VariableType::OBJECT_TYPE:
		return 13;
	default:
		break ;
	}
	return 13;
}
void TypedVariableDeclare::int2enum(int num, ThreadContext* ctx) throw() 
{
	switch(num) {
	case 1:
		this->typeEnum = VariableType::BOOL_TYPE;
		break ;
	case 2:
		this->typeEnum = VariableType::BYTE_TYPE;
		break ;
	case 3:
		this->typeEnum = VariableType::SHORT_TYPE;
		break ;
	case 4:
		this->typeEnum = VariableType::CHAR_TYPE;
		break ;
	case 5:
		this->typeEnum = VariableType::INT_TYPE;
		break ;
	case 6:
		this->typeEnum = VariableType::LONG_TYPE;
		break ;
	case 7:
		this->typeEnum = VariableType::FLOAT_TYPE;
		break ;
	case 8:
		this->typeEnum = VariableType::DOUBLE_TYPE;
		break ;
	case 9:
		this->typeEnum = VariableType::STRING_TYPE;
		break ;
	case 10:
		this->typeEnum = VariableType::TIMESTAMP;
		break ;
	case 11:
		this->typeEnum = VariableType::TIME;
		break ;
	case 12:
		this->typeEnum = VariableType::BIGDECIMAL;
		break ;
	case 13:
	default:
		this->typeEnum = VariableType::OBJECT_TYPE;
		break ;
	}
}
}}}

