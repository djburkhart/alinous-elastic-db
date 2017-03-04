#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.compile/ExpressionSourceId.h"
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
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
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
#include "alinous.system.utils/FileUtils.h"
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
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchingException.h"
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
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionRef.h"
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
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
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
#include "alinous.html/DomText.h"
#include "alinous.html/DomComment.h"
#include "alinous.html/AlinousDomEventHandler.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/DomTokenizer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.system.config/ConfigPathUtils.h"
#include "alinous.system.config.remote/Table.h"
#include "alinous.system.config.remote/Tables.h"
#include "alinous.system.config.remote/Node.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.utils/ConfigFileUtiles.h"
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
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"

namespace alinous {namespace system {namespace config {





bool AlinousConfig::__init_done = __init_static_variables();
bool AlinousConfig::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousConfig", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousConfig::AlinousConfig(String* home, ThreadContext* ctx) throw()  : IObject(ctx), alinousHome(__GC_INS(this, (new(ctx) StringBuffer(ctx)), StringBuffer)), system(nullptr), database(nullptr), mail(nullptr), alinousDb(nullptr), webHandler(nullptr), regions(GCUtils<List<RegionsServer> >::ins(this, (new(ctx) ArrayList<RegionsServer>(ctx)), ctx, __FILEW__, __LINE__, L"")), nodes(nullptr), monitor(nullptr), alinousConfigPath(nullptr), fileTimestamp(0)
{
	this->alinousHome->append(home, ctx);
	if(!home->endsWith(ConstStr::getCNST_STR_1007(), ctx))
	{
		this->alinousHome->append(ConstStr::getCNST_STR_1007(), ctx);
	}
}
void AlinousConfig::__construct_impl(String* home, ThreadContext* ctx) throw() 
{
	this->alinousHome->append(home, ctx);
	if(!home->endsWith(ConstStr::getCNST_STR_1007(), ctx))
	{
		this->alinousHome->append(ConstStr::getCNST_STR_1007(), ctx);
	}
}
 AlinousConfig::~AlinousConfig() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousConfig::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousConfig", L"~AlinousConfig");
	__e_obj1.add(this->alinousHome, this);
	alinousHome = nullptr;
	__e_obj1.add(this->system, this);
	system = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->mail, this);
	mail = nullptr;
	__e_obj1.add(this->alinousDb, this);
	alinousDb = nullptr;
	__e_obj1.add(this->webHandler, this);
	webHandler = nullptr;
	__e_obj1.add(this->regions, this);
	regions = nullptr;
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	__e_obj1.add(this->monitor, this);
	monitor = nullptr;
	__e_obj1.add(this->alinousConfigPath, this);
	alinousConfigPath = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousConfig::parseInitFile(ThreadContext* ctx)
{
	__GC_MV(this, &(this->alinousConfigPath), this->alinousHome->clone(ctx)->append(ConstStr::getCNST_STR_1245(), ctx), String);
	String* encode = ConstStr::getCNST_STR_1106();
	File* confFile = (new(ctx) File(this->alinousConfigPath, ctx));
	this->fileTimestamp = confFile->lastModified(ctx);
	String* xmlSrc = FileUtils::readAllText(this->alinousConfigPath, encode, ctx);
	if(xmlSrc == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1246(), ctx));
	}
	AlinousDomReplacer* replacer = (new(ctx) AlinousDomReplacer(ctx));
	DomConverter* converter = (new(ctx) DomConverter(xmlSrc, replacer, ctx));
	converter->parse(ctx);
	DomDocument* document = replacer->getDocument(ctx);
	Matcher* matcher = (new(ctx) Matcher(ctx));
	MatchCandidatesCollection* result = nullptr;
	{
		try
		{
			result = matcher->match(document, document, ConstStr::getCNST_STR_1247(), ctx);
			handleSystem(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1248(), ctx);
			handleAlinousDbSetting(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1249(), ctx);
			handleSourceSetting(result, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1250(), ctx);
			handleWebSetting(result, document, matcher, ctx);
			result = matcher->match(document, document, ConstStr::getCNST_STR_1251(), ctx);
			handleMailSetting(result, ctx);
			handleDistributedDbParts(document, matcher, ctx);
		}
		catch(alinous::parser::xpath::ParseException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1252(), ctx));
		}
		catch(MatchingException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1252(), ctx));
		}
	}
}
StringBuffer* AlinousConfig::getAlinousHome(ThreadContext* ctx) throw() 
{
	return alinousHome;
}
void AlinousConfig::setAlinousHome(StringBuffer* alinousHome, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousHome), alinousHome, StringBuffer);
}
SystemInfo* AlinousConfig::getSystem(ThreadContext* ctx) throw() 
{
	return system;
}
DataSourceInfo* AlinousConfig::getDatabase(ThreadContext* ctx) throw() 
{
	return database;
}
MailInfo* AlinousConfig::getMail(ThreadContext* ctx) throw() 
{
	return mail;
}
AlinousDbInfo* AlinousConfig::getAlinousDb(ThreadContext* ctx) throw() 
{
	return alinousDb;
}
WebHandlerInfo* AlinousConfig::getWebHandler(ThreadContext* ctx) throw() 
{
	return webHandler;
}
String* AlinousConfig::getAlinousConfigPath(ThreadContext* ctx) throw() 
{
	return alinousConfigPath;
}
long long AlinousConfig::getFileTimestamp(ThreadContext* ctx) throw() 
{
	return fileTimestamp;
}
List<RegionsServer>* AlinousConfig::getRegions(ThreadContext* ctx) throw() 
{
	return regions;
}
Nodes* AlinousConfig::getNodes(ThreadContext* ctx) throw() 
{
	return nodes;
}
Monitor* AlinousConfig::getMonitor(ThreadContext* ctx) throw() 
{
	return monitor;
}
void AlinousConfig::handleSystem(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1253(), ctx));
	}
	if(list->size(ctx) > 1)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1254(), ctx));
	}
	__GC_MV(this, &(this->system), (new(ctx) SystemInfo(this->alinousHome->toString(ctx), ctx)), SystemInfo);
	MatchCandidate* candidate = list->get(0, ctx);
	String* moduleDir = ConfigFileUtiles::getText(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1255(), ctx);
	if(moduleDir != nullptr)
	{
		this->system->setModuleDir(moduleDir->trim(ctx), ctx);
	}
	String* systemDatastore = ConfigFileUtiles::getAttribute(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1256(), ConstStr::getCNST_STR_1257(), ctx);
	if(systemDatastore != nullptr)
	{
		this->system->setSystemDatastore(systemDatastore->trim(ctx), ctx);
	}
	String* defaultDatastore = ConfigFileUtiles::getAttribute(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1258(), ConstStr::getCNST_STR_1257(), ctx);
	if(defaultDatastore != nullptr)
	{
		this->system->setDefaultDatastore(defaultDatastore->trim(ctx), ctx);
	}
}
void AlinousConfig::handleDistributedDbParts(DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	MatchCandidatesCollection* result = nullptr;
	ArrayList<MatchCandidate>* list = nullptr;
	result = matcher->match(document, document, ConstStr::getCNST_STR_1259(), ctx);
	list = result->getCandidatesList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		MatchCandidate* candidate = list->get(i, ctx);
		RegionsServer* regsrv = RegionsServer::parseInstance(candidate, document, matcher, ctx);
		this->regions->add(regsrv, ctx);
	}
	result = matcher->match(document, document, ConstStr::getCNST_STR_1260(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		__GC_MV(this, &(this->nodes), Nodes::parseInstance(candidate, document, matcher, this->alinousHome->toString(ctx), ctx), Nodes);
	}
	result = matcher->match(document, document, ConstStr::getCNST_STR_1261(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		__GC_MV(this, &(this->monitor), Monitor::parseInstance(candidate, document, matcher, ctx), Monitor);
	}
}
void AlinousConfig::handleAlinousDbSetting(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		return;
	}
	__GC_MV(this, &(this->alinousDb), (new(ctx) AlinousDbInfo(this->alinousHome->toString(ctx), ctx)), AlinousDbInfo);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* candidate = it->next(ctx);
		DomNode* node = candidate->getCandidateDom(ctx);
		IVariableValue* attr = node->getAttributeValue(ConstStr::getCNST_STR_1257(), ctx);
		if(attr == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1262(), ctx));
		}
		String* id = attr->toString(ctx)->trim(ctx);
		String* dataDir = ConfigFileUtiles::getText(document, candidate->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1263(), ctx);
		if(dataDir == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1264(), ctx));
		}
		AlinousDbInstanceInfo* dbinfo = this->alinousDb->addInstance(id, dataDir->trim(ctx), ctx);
		handleRemoteRef(dbinfo, node, document, matcher, ctx);
	}
}
void AlinousConfig::handleRemoteRef(AlinousDbInstanceInfo* dbinfo, DomNode* alinousDb, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	MatchCandidatesCollection* result = nullptr;
	ArrayList<MatchCandidate>* list = nullptr;
	result = matcher->match(document, alinousDb, ConstStr::getCNST_STR_1265(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		RegionsRef* regionsRef = RegionsRef::parseInstance(candidate, document, matcher, ctx);
		dbinfo->setRegionsRef(regionsRef, ctx);
	}
	result = matcher->match(document, alinousDb, ConstStr::getCNST_STR_1266(), ctx);
	list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		MonitorRef* monitorRef = MonitorRef::parseInstance(candidate, document, matcher, ctx);
		dbinfo->setMonitorRef(monitorRef, ctx);
	}
}
void AlinousConfig::handleWebSetting(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		return;
	}
	__GC_MV(this, &(this->webHandler), (new(ctx) WebHandlerInfo(this->alinousHome->toString(ctx), ctx)), WebHandlerInfo);
	MatchCandidate* candidateWebHandler = list->get(0, ctx);
	DomNode* node = candidateWebHandler->getCandidateDom(ctx);
	IVariableValue* attr = node->getAttributeValue(ConstStr::getCNST_STR_1267(), ctx);
	if(attr != nullptr)
	{
		String* portStr = attr->toString(ctx)->trim(ctx);
		{
			try
			{
				int port = Integer::parseInt(portStr, ctx);
				this->webHandler->setPort(port, ctx);
			}
			catch(NumberFormatException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	String* documentRoot = ConfigFileUtiles::getText(document, candidateWebHandler->getCandidateDom(ctx), matcher, ConstStr::getCNST_STR_1268(), ctx);
	if(document != nullptr)
	{
		this->webHandler->setDocumentRoot(documentRoot, ctx);
	}
}
void AlinousConfig::handleSourceSetting(MatchCandidatesCollection* result, ThreadContext* ctx) throw() 
{
}
void AlinousConfig::handleMailSetting(MatchCandidatesCollection* result, ThreadContext* ctx) throw() 
{
}
}}}

